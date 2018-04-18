# from PIL import Image, ImageFilter
import requests
from collections import OrderedDict

# url = 'http://google.com/favicon.ico'
# r = requests.get(url, allow_redirects=True)
# open('google.ico', 'wb').write(r.content)

class MyImage:
	def __init__(self,url):
		r = requests.get(url, allow_redirects=True)
		self.url = url
		self.image = r.content
		self.size = len(r.content)


class ImageLRU:
	def __init__(self,capacity):
		self.cap = capacity
		self.cur_size = 0
		self.cache = OrderedDict()

	def get(self, url):
		print(url)
		if url in self.cache:
			self.cache.move_to_end(url)
			print("IN CACHE")
		self.add(url)

	def add(self,url):
		if url in self.cache:
			pass
		else:
			try:	
				newimage = MyImage(url)
				while newimage.size + self.cur_size > self.cap:
					( _, popimage) = self.cache.popitem(last=False)
					self.cur_size = self.cur_size - popimage.size					
				self.cache[url] = newimage
				self.cur_size = self.cur_size + newimage.size
				print("DOWNLOADED %d %d/%d"%(newimage.size,self.cur_size,self.cap))
				
			except:
				# print(error)
				print("Download error")

def main(filepath):
	url_list = []
	with open(filepath,'rb') as f:
		for line in f:
			url_list.append(line[:-1])
	lru = ImageLRU(int(url_list[0]))
	for i in range(2,int(url_list[1])+2):
		lru.get(url_list[i])


if __name__ == '__main__':
	filepath = './input.txt'
	main(filepath)