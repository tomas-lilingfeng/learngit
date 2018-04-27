from numpy import *  
import operator  
import os
   
def createDataSet():  
    group = array([[1.0,1.1],[1.0,1.0],[0,0],[0,0.1]])  
    labels = ['A','A','B','B']  
    return group,labels  
	
#k-近邻分类算法  
def classify0(inX, dataSet, labels, k): #4个输入参数分别为：
    #用于分类的输入向量inX，输入的训练样本集dataSet，标签向量labels，选择最近邻居的数目k  
    #计算距离  
    dataSetSize=dataSet.shape[0]  #获取数据集的宽  
    diffMat=tile(inX, (dataSetSize, 1))-dataSet #使用欧式距离度量，故将输入向量和数据集中各向量相减  
    sqDiffMat=diffMat**2  #平方  
    sqDistances=sqDiffMat.sum(axis=1)  #计算输入向量和数据集中各向量之间的差的平方和  
    distances=sqDistances**0.5  #计算欧式距离  
    #选择距离最小的k个点 计算所属类别的出现频率  
    sortedDistIndicies=distances.argsort() #取得输入向量和数据集中各向量欧式距离的从小到大排序的下标值  
    classCount={}  #定义一个空字典  
    for i in range(k):  #取计算欧氏距离排序后最小的前k个值  
        voteIlabel=labels[sortedDistIndicies[i]]  
        classCount[voteIlabel]=classCount.get(voteIlabel,0)+1  
    #排序 选择前k个点中出现最多的那一个类  classCountl类似于{'B':2,'A':1}是dict
    sortedClassCount=sorted(classCount.items(), key=operator.itemgetter(1), reverse=True)  
    return sortedClassCount[0][0]  
	
	
def file2matrix(filename):
	fr=open(filename)          #打开datingTestSet2.txt
	arrayOLines=fr.readlines()  #读取每一行的内容
	numberOfLines=len(arrayOLines)    #记录训练集的行数（即样本数）
	returnMat=zeros((numberOfLines,3))#创建 训练集的行数*3的零矩阵  one_like与之类似用一填满
	classLabelVector=[]     #创建一个空列表
	index=0
	for line in arrayOLines:    #arrayOLines为读取的每一行
		line=line.strip()     #去掉首尾空白符
		listFormLine=line.split('\t') #利用空格符分离字符串
		returnMat[index,:]=listFormLine[0:3]   #将每行样本数据的前3个数据输入返回样本矩阵中
		classLabelVector.append(int(listFormLine[-1]))  #将每行样本数据的最后一个数据加入类标签向量中 
		index+=1
	return returnMat,classLabelVector  #返回训练样本矩阵和类标签向量 

	
#归一化特征值  
def autoNorm(dataSet): #输入为数据集数据  
    minVals=dataSet.min(0) #获得数据集中每列的最小值  
    maxVals=dataSet.max(0) #获得数据集中每列的最大值  
    ranges=maxVals-minVals #获取取值范围  
    normDataSet=zeros(shape(dataSet)) #初始化归一化数据集  shape()获取矩阵的（行，列）
    m=dataSet.shape[0] #行  
    normDataSet=dataSet-tile(minVals, (m, 1))  
    normDataSet=normDataSet/tile(ranges, (m, 1)) #特征值相除  
    return normDataSet, ranges, minVals #返回归一化矩阵，取值范围以及最小值  
  
#测试程序  
def datingClassTest(kValue=4):  
    hoRatio=0.10 #取测试样本占数据集样本的10%  
    datingDataMat,datingLabels=file2matrix('datingTestSet2.txt') #得到样本集，样本标签  
    normMat,ranges,minVals=autoNorm(datingDataMat) #得到归一化样本集，取值范围以及最小值  
    m=normMat.shape[0] #样本集行数  
    numTestVecs=int(m*hoRatio) #测试样本集数量   
    errorCount=0.0 #初始化错误率  
    for i in range(numTestVecs): #循环，计算测试样本集错误数量  
        classifierResult=classify0(normMat[i,:], normMat[numTestVecs:m,:], datingLabels[numTestVecs:m], kValue) #k-近邻算法  
        print ("the classifier came back with: %d, the real answer is: %d"%(classifierResult, datingLabels[i]))   
        if (classifierResult != datingLabels[i]):  
            errorCount+=1.0
    print ("the total error rate is: %f"%(errorCount/float(numTestVecs))) #计算错误率，并输出  
  


def classifyPerson():
		resultList=['not at all','in small doses','in large doses']
		percentTats=float(input('percenttage of time spent playing video game?'))
		ffMiles=float(input('frequent filer miles earned per year?'))
		iceCream=float(input('liters of icecream consumed per year?'))
		datingDataMat,datingLabels=file2matrix('datingTestSet2.txt')
		normMat,ranges,minVals=autoNorm(datingDataMat)
		inArr=array([ffMiles, percentTats, iceCream])
		classifierResult=classify0((inArr-minVals)/ranges,normMat,datingLabels,3)
		print ("You will probably like this person: ",resultList[classifierResult-1] )
		
		
def img2vector(filename):
	returnVect=zeros((1,1024))
	fr=open(filename)
	for i in range(32):
		lineStr=fr.readline()
		for j in range(32):
			returnVect[0,32*i+j]=int(lineStr[j])
	return returnVect
	

def handwritingClassTest(kValue=3):
	hwLabels=[]
	trainingFileList=os.listdir('trainingDigits')
	m=len(trainingFileList)
	trainingMat=zeros((m,1024))
	for i in range(m):
		fileNameStr=trainingFileList[i]
		fileStr=fileNameStr.split('.')[0]
		classNumStr=int(fileStr.split('_')[0])
		hwLabels.append(classNumStr)
		trainingMat[i,:]=img2vector('trainingDigits/%s' % fileNameStr)
	testFileList=os.listdir('testDigits')
	errorCount=0.0
	mTest=len(testFileList)
	for i in range(mTest):
		fileNameStr=testFileList[i]
		fileStr=fileNameStr.split('.')[0]
		classNumStr=int(fileStr.split('_')[0])
		vectorUnderTest=img2vector('trainingDigits/%s' % fileNameStr)
		classifierResult=classify0(vectorUnderTest,trainingMat,hwLabels,kValue)
		#print("the classifier came back with : %d,the real answer is : %d" % (classifierResult,classNumStr))
		if(classifierResult!=classNumStr):
			errorCount+=1
	print('\nthe total number of errors is: %d' % errorCount)
	print('\nthe total error rate is: %f' % (errorCount/float(mTest)))
	
	

	
	
	
	
	
	
	
	