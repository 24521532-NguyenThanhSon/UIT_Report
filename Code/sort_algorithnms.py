import timeit
import time
data_list = ["data1.txt","data2.txt","data3.txt","data4.txt","data5.txt","data6.txt","data7.txt","data8.txt","data9.txt","data10.txt"]
sortingtime_data = ["sorting_data1.txt","sorting_data2.txt","sorting_data3.txt","sorting_data4.txt","sorting_data5.txt","sorting_data6.txt","sorting_data7.txt","sorting_data8.txt","sorting_data9.txt","sorting_data10.txt"]

for i in range(10):
    with open(data_list[i],"r", encoding = "utf-8") as file:
        array = list(map(int,file.read().split()))
    array = array[1:]
    
    start = time.time()
    sorted(array)
    end = time.time()
    with open(sortingtime_data[i],"a", encoding = "utf-8") as sort_time:
        sort_time.write(f"{round(((end - start)*1000),3)}")
        
    
    
