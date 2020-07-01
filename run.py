import os
a = 3

while a<16:
	f = open("sample-param.txt","r")
	filestring = ""
	for s in f:
		temp = s
		s1 = str.split(s,"=")
		#print(s1)
		if s1[0] == "agentnum":
			string = s1[0] + "=" + str(a) + "\n"
			#print("Hello")
			filestring += string 
		else:
			filestring += temp 
	#print(filestring)
	f.close()
	fw = open("sample-param.txt","w") 
	fw.write(filestring)
	fw.close()
	#print(!make crun param=sample-param.txt)
	os.system("make crun param=sample-param.txt")
	a += 1
		
	
