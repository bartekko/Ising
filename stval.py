from sys import argv
magnetizations=[]
energies=[]

with open(argv[1]) as data:
	while(True):
		fm=data.readline()
		if fm=='': break;	
		line=[float(i) for i in fm.strip().split(' ')]
		#print(line)
		magnetizations.append(line[0])
		energies.append(line[1])
		
	#print(sum([abs( a )for a in magnetizations])/len(magnetizations))
	print(sum([abs (a) for a in energies])/len(magnetizations))
