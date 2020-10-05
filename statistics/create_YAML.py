import yaml
a = 130
while a <= 180:
    f = open("/home/mustafizur/pibt/32by32/kivalike_0_" + str(a) + "_3.000000.txt","r")
    i = 0
    j = 0
    agents = 0
    agent_info = list()

    dict_map = dict()
    dict_map['agents'] = list()
    dict_map["map"] = dict()

    for s in f:
        data = str.split(s,",")
        #print(data)
        if i == 0:
            agents = int(data[0])
        else :
            strow = int(data[0])
            stcol = int(data[1])
            enrow = int(data[2])
            encol = int(data[3])
            agent_dict = {}
            agent_dict['goal'] = [enrow,encol]
            agent_dict['name'] = "agent"+str(i-1)
            agent_dict['start'] = [strow,stcol]
            agent_info.append(agent_dict)
        i += 1

    dict_map['agents'] = agent_info

    f = open("/home/mustafizur/pibt/map/kivalike.map","r")
    i = 0
    height =0
    width = 0
    obstacles = list()
    for s in f:
        j = 0
        data = str.split(s," ")
        #print(data)
        if i == 0:
            height = int(data[1])
        elif i == 1:
            width = int(data[1])
        if i>2:
            k = 0
            for char in s:
                #print(char)
                if char == 'T':
                    temp = list()
                    temp.append(i-3)
                    temp.append(k)
                    #print(temp)
                    obstacles.append(temp)
                k += 1
        i += 1

    dimensions = list()
    dimensions.append(height)
    dimensions.append(width)

    dict_file = dict()
    dict_file['obstacles'] = list()
    dict_file['dimensions'] = list()
    dict_file['obstacles']=obstacles
    dict_file['dimensions']=dimensions


    dict_map["map"]=dict_file

    #print(obstacles)

    with open('kivalike_0_' + str(a) + '_3.000000.yaml', 'w') as file:
        documents = yaml.dump(dict_map, file)
    a += 10