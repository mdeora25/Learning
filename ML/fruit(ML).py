## importing sklearn
from sklearn import tree
## defining features and labels
features = [[140,1],[130,1],[150,0],[170,0]]
labels = [0,0,1,1]
## defining a classifiers 
clf = tree.DecisionTreeClassifier()
## training classifiers 
clf = clf.fit(features, labels)
# user input
weight= input('enter a weight: ')
surface= input('is it bumpy or smooth: ')
## checking weight
if int(weight) < 200 and int(weight) > 120 :
		weight1 = int(weight)

else:
		print("use a diffrent weight 120<x<200")
## checking surface and converting 
if surface == "smooth":
	surface=1

elif surface == "bumpy" :
		surface=0
else:
	print("please choose bumpy or smooth")
		
## prediction 
clf.predict([[weight1,surface]])
print(clf.predict([[weight1,surface]]))
## printing results 
if  clf.predict([[weight1,surface]]) == 1:
	print("this is an Orange")
else:
	print("this is an Apple")
## apending items
features.append([weight1, surface])
labels.append(clf.predict([[weight1,surface]]))

