class Student:
    def __init__(self, name, student_number):
        # initialize class attributes
        self.name = name
        self.student_number = student_number
        self.classes = []

    def enrol(self, course_running):
        self.classes.append(course_running)
        course_running.add_student(self)


class Department:
    def __init__(self, name, department_code):
        self.name = name
        self.department_code = department_code
        self.courses = {}

    def add_course(self, description, course_code, credits):
        self.courses[course_code] = Course(description, course_code, credits, self)
        return self.courses[course_code]


class Course:
    def __init__(self, description, course_code, credits, department):
        self.description = description
        self.course_code = course_code
        self.credits = credits
        self.department = department
        #self.department.add_course(self)

        self.runnings = []

    def add_running(self, year):
        self.runnings.append(CourseRunning(self, year))
        return self.runnings[-1]

    def __str__(self):
        return f"{self.description}"


class CourseRunning:
    def __init__(self, course, year):
        self.course = course
        self.year = year
        self.students = []
    def __str__(self):
        return f"{self.course} {self.year}"

    def add_student(self, student):
        self.students.append(student)


def main():
    fis_dept = Department("Physics and Applied Computer Science", "FIS")
    print(fis_dept.name)
    print(fis_dept.department_code)
    print(fis_dept.courses)
    fis_pite = fis_dept.add_course("Python in the Enterptise", "PitE", 5)
    fis_pite_2021 = fis_pite.add_running(2021)
    print(fis_dept.courses)
    print(fis_pite_2021)
    bob = Student("Bob", "Smith")
    bob.enrol(fis_pite_2021)
    print(bob.classes)



if __name__ == '__main__':
    main()