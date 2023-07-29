#I considered that the largest mark is 100 and cannot be exceeded

N = int
# make sure that the input is integer
while True:
    the_input = input("Enter Student number please: ")
    if the_input.isdigit() and int(the_input)>0 :
        N=int(the_input)
        break
    else:
        print("the input must be a positive number:")

student_grade_dic={}

for i in range(N):
    st_name=input('please enter Student\'s name number '+str(i+1)+":")
    while True:
        st_grade = input("Enter the mark of the student "+st_name+" :")
        if st_grade.isdigit() and int(st_grade)>0 :
            st_grade=int(st_grade)
            break
        else:
            print("the input must be a positive number:")

    student_grade_dic[st_name]=st_grade


student_grade_dic['Hamad']=58


#Add 5 marks based on the given condition 
student_grade_dic={st_name:min(grade+5,100) if grade>85  else grade  for st_name,grade in student_grade_dic.items()}

print("------Students List------")
for st_name,st_grade in student_grade_dic.items():
    print(st_name)


max_grade=max(student_grade_dic.values())   
print("------The students who obtained the highest grade.------")
for st_name,st_grade in student_grade_dic.items():
    if st_grade==max_grade :
        print(st_name+"=> "+str(st_grade))
