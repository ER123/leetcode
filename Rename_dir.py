#coding:utf-8
import os

def rename(dir):
	for dir_list in os.listdir(dir):
		print("dir_list:",dir_list)
		idx = 0
		if os.path.isdir(dir_list):

			for dir_list_list in os.listdir(dir_list):
				print("dir_list_list:",dir_list_list)
				check_dir_name = os.path.join(dir_list[0], dir_list_list)
				if os.path.isdir(check_dir_name):
					print(check_dir_name+" is a dir")
					if "模糊" in check_dir_name:
						dir_name = check_dir_name.replace("模糊", "mohu")
						print(dir_name)
						os.rename(check_dir_name, dir_name)
						
					elif "清楚" in check_dir_name:
						dir_name = check_dir_name.replace("清楚", "qingchu")
						print(dir_name)
						os.rename(check_dir_name, dir_name)
						
				else:
					print(check_dir_name+" is not a dir")

			idx += 1


if __name__ == '__main__':
	dir = "E:\\test_for_cmd"
	rename(dir)
