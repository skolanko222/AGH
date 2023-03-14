# Exercise:  INHERITANCE

# Add class “WFiIS_Student” which will be a subclass of class Student.
# Add __init__ method, that inherits from Student but also initializes attributes that are special for WFiS Students… ( taurus account? e-mail @fis.agh.edu.pl ?)

# You may add some logic inside main() to play around with its behaviour. e.g.
# check if WFIS_Student has inherited __str__ method correctly...

# You may also modify the __str__ in order to show also e-mail address in fis domain.

class Person:
    def __init__(self, name, surname, number):
        self.name = name
        self.surname = surname
        self.number = number

    # magic (dunder) method - we will talk about it soon...
    def __str__(self):
        return f'{self.number}: {self.surname}, {self.name}'


class Student(Person):
    UNDERGRADUATE, POSTGRADUATE = range(2)

    def __init__(self, student_type, name, surname, number):
        self.student_type = student_type
        self.classes = []
        super().__init__(name, surname, number)

    def enrol(self, course):
        self.classes.append(course)



class StaffMember(Person):
    PERMANENT, TEMPORARY = range(2)

    def __init__(self, employment_type, name, surname, number):
        self.employment_type = employment_type
        super().__init__(name, surname, number)



class Lecturer(StaffMember):
    def __init__(self, employment_type, name, surname, number):
        self.courses_taught = []
        super().__init__(employment_type, name, surname, number)

    def assign_teaching(self, course):
        self.courses_taught.append(course)


class WFiIS_Student(Student):
    def __init__(self,taurus_username,taurus_password,student_type,name,surname,number):
        super().__init__(student_type, name, surname, number)
        self.taurus_username = taurus_username
        self.taurus_password = taurus_password
    
    def __str__(self):
        return f'{self.number}: {self.surname}, {self.name}, {self.taurus_username}'




def main():
    
    jane = Student(Student.POSTGRADUATE, "Jane", "Smith", "123456789")
    jane.enrol('a_postgrad_course')
    print(jane)


    bob = Lecturer(StaffMember.PERMANENT, "Bob", "Jones", "123456789")
    bob.assign_teaching('an_undergrad_course')

    
    james = WFiIS_Student("1james","123qwer",Student.UNDERGRADUATE,"James","Clinton","1234555")
    james.enrol('an_undergraduate__course')
    print(james)


if __name__ == '__main__':
    main()