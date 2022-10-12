#!/usr/bin/python
from Crypto.Hash import SHA512
import sys 
import os 
import os.path

def hashAFile(fname):
	blockSize = 65536
	hasher = SHA512.new()
	with open (fname, 'rb') as aFile:
		buf = aFile.read(blockSize)
		while len(buf) > 0:
			hasher.update(buf)
			buf = aFile.read(blockSize)
	return hasher

def getFileList(folderName):
	fileList = []
	folderList = os.listdir(folderName)
	
	for f in folderList:
		if os.path.isfile(f):
			fileList.append(f)
	return fileList

def main(argv):
	folder = ""
	if len(argv) < 2:
		folder = os.getcwd()
	else:
		folder = argv[1]	
	
	fileList = getFileList(folder)
	for i in fileList:
		hashh = hashAFile(i)
		print("File:",i,"\nHash:",hashh.hexdigest(),"\n")


if __name__ == "__main__":
	main(sys.argv)

