import os
agent = 10
# while agent < 40:
# ex = 0
# j = 1.25
# while j <= 5.25:
# 	ex = 0
# 	while ex<100:
# 		# j = 1.25
# 		# while j<6:
# 		a = 20
# 		while a<=100:
# 			f = open("sample-param.txt","r")
# 			filestring = ""
# 			for s in f:
# 				temp = s
# 				s1 = str.split(s,"=")
# 				#print(s1)
# 				if s1[0] == "agentnum":
# 					string = s1[0] + "=" + str(a) + "\n"
# 					filestring += string
# 					#print("Hello")
# 				#filestring += string 
# 				elif s1[0] == "suboptimal":
# 					string = s1[0] + "=" + str(j) + "\n"
# 					filestring += string
# 				elif s1[0] == "field":
# 					string = s1[0] + "=./map/32by32_agents10" + "_ex" + str(ex)+ ".map\n"
# 					filestring += string
# 				else:
# 					filestring += temp 
# 			print(filestring)
# 			f.close()
# 			fw = open("sample-param.txt","w") 
# 			fw.write(filestring)
# 			fw.close()
# 			#print(!make crun param=sample-param.txt)
# 			os.system("make crun param=sample-param.txt")
# 			a += 20
# 			# j += 1
# 		ex += 1
# 	j += 1
# 		# agent += 10


seed = 0
while seed < 100:
	j = 1.25
	while j<6:
		a = 30
		while a<241:
			f = open("sample-param.txt","r")
			filestring = ""
			for s in f:
				temp = s
				s1 = str.split(s,"=")
				# print(s1)
				if s1[0] == "agentnum":
					string = s1[0] + "=" + str(a) + "\n"
					#print("Hello")
					filestring += string 
				elif s1[0] == "suboptimal":
					string = s1[0] + "=" + str(j) + "\n"
					filestring += string
				elif s1[0] == "seed":
					string = s1[0] + "=" + str(seed) + "\n"
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
			a += 30
		j += 1
	seed += 1
		
	
