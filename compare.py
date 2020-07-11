# import os
# agent = 1
# cnt1 = 0
# cnt2 = 0
# while agent < 4:
# 	ex = 0
# 	while ex<100:
# 		j = 1.25
# 		while j<6:
# 			a = 5
#             while a < 21 :
#                 if (os.path.exists("./log/8by8_agents" + str(agent) +"_ex" + str(ex)+ "_" + str(a) + "_" + str(j) + ".txt") and not os.path.exists("./changed_log/8by8_agents" + str(agent) +"_ex" + str(ex)+ "_" + str(a) + "_" + str(j) + ".txt")):
#                     cnt1 = cnt1 + 1
#                     print("8by8_agents" + str(agent) +"_ex" + str(ex)+ "_" + str(a) + "_" + str(j) + ".txt")
#                     os.remove("./log/8by8_agents" + str(agent) +"_ex" + str(ex)+ "_" + str(a) + "_" + str(j) + ".txt")
#                 elif not os.path.exists("./log/8by8_agents" + str(agent) +"_ex" + str(ex)+ "_" + str(a) + "_" + str(j) + ".txt") and os.path.exists("./changed_log/8by8_agents" + str(agent) +"_ex" + str(ex)+ "_" + str(a) + "_" + str(j) + ".txt"):
#                     cnt2 += 1
#                     os.remove("./changed_log/8by8_agents" + str(agent) +"_ex" + str(ex)+ "_" + str(a) + "_" + str(j) + ".txt")
#                     print("8by8_agents" + str(agent) +"_ex" + str(ex)+ "_" + str(a) + "_" + str(j) + ".txt")
# 			    a += 5
# 			j += 1
# 		ex += 1
# 	agent += 1

# print(cnt1,cnt2)

import os
agent = 1
while agent < 4:
	ex = 0
	while ex<100:
		j = 1.25
		while j<6:
			a = 5
			while a<21:
				f = open("sample-param.txt","r")
				filestring = ""
				for s in f:
					temp = s
					s1 = str.split(s,"=")
					print(s1)
					if s1[0] == "agentnum":
						string = s1[0] + "=" + str(a) + "\n"
						#print("Hello")
						filestring += string 
					elif s1[0] == "suboptimal":
						string = s1[0] + "=" + str(j) + "\n"
						filestring += string
					elif s1[0] == "field":
						string = s1[0] + "=./map/8by8_agents" + str(agent) +"_ex" + str(ex)+ ".map\n"
						filestring += string
					else:
						filestring += temp 
				print(filestring)
				f.close()
				fw = open("sample-param.txt","w") 
				fw.write(filestring)
				fw.close()
				#print(!make crun param=sample-param.txt)
				os.system("make crun param=sample-param.txt")
				a += 5
			j += 1
		ex += 1
	agent += 1
		
	


	
# 8by8_agents1_ex0_5_1.250000.txt