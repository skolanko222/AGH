# Exercise: *args, **kwargs
# Change parameters in __init__ of all subclasses of class Person (Student, StaffMember, Lecturer) into 
# (*args, **kwargs) on the basis of example below. 
# Then check how it works. 



# class MySubclass(Superclass):
#     def __init__(self, subclass_value, *args, **kwargs):
#         self.myvalue = kwargs.pop('myvalue', None)
#         self.subclass_value = subclass_value
#         super().__init__(*args, **kwargs)



class Person:
    def __init__(self, *args, **kwargs):
        self.name = kwargs.pop('name', None)
        self.surname = kwargs.pop('surname', None)
        self.number = kwargs.pop('number', None)

class Student(Person):
    UNDERGRADUATE, POSTGRADUATE = range(2)

    def __init__(self, *args, **kwargs):
        self.student_type = kwargs.pop('student_type', None)
        self.classes = []
        super().__init__(*args, **kwargs)

    def enrol(self, course):
        self.classes.append(course)



class StaffMember(Person):
    PERMANENT, TEMPORARY = range(2)

    def __init__(self, *args, **kwargs):
        self.employment_type = kwargs.pop('employment_type', None)
        super().__init__(*args, **kwargs)



class Lecturer(StaffMember):
    def __init__(self, *args, **kwargs):
        self.courses_taught = []
        super().__init__(*args, **kwargs)

    def assign_teaching(self, course):
        self.courses_taught.append(course)



def main():
    
    jane = Student(Student.POSTGRADUATE, name="Jane", surname="Smith", number="123456789")
    jane.enrol('a_postgrad_course')
    print(jane)


    bob = Lecturer(StaffMember.PERMANENT, name="Bob", surname="Jones",number="123456789")
    bob.assign_teaching('an_undergrad_course')


if __name__ == '__main__':
    main()