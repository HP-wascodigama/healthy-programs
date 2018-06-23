#List example: employee details
ID=c(1,2,3,4)
emp.name=c("man","rag","sha","din")
num.emp=4
emp.list=list(ID,emp.name,num.emp)
print(emp.list)
#accessing components(by names)
print(emp.list[[1]])
print(emp.list[[2]])
print(emp.list[[2]][1])
print(emp.list$Names)
#Manipulating list
emp.list[[2]][5]="Nir"
emp.list[[1]][5]=5
print(emp.list)
#concatenation of list
emp.ages=list("ages"=c(23,54,30,32))
emp.list=c(emp.list,emp.ages)
print(emp.list)