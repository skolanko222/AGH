class Student:
    UNIVERSITY_NAME = "AGH University of Science and Technology"
	
    def __init__(self, name, score):
        self.name = name
        self.__score = score    # score is made private

    @property
    def email(self):
        return self.name + '@agh.edu.pl'

    # our property methods for score (getter)  
    @property
    def score(self):
        print("Getting score...")
        return self.__score

    @score.setter
    def score(self, value):
        print("Setting score...")
        self.__score = value

    @score.deleter
    def score(self):
        print("Deleting score...")
        del self.__score

    @classmethod
    def show_short_ver_of_uni_name(cls):
        print(cls.UNIVERSITY_NAME.split()[0])


    @classmethod
    def createfrom_str(cls, stud_str):
        name = stud_str.split('_')[0]
        score = stud_str.split('_')[1]
        return cls(name, score)

    @staticmethod
    def return_score_by_percentage(self,score, total):
        return int(score) /total * 100


    def print_full_info(self):
        print(self.UNIVERSITY_NAME)
        print(self.name, self.score, self.return_score_by_percentage(self.score,5,100), "%")



if __name__ == '__main__':
    jane = Student("Jane", '5')
    print(jane.name)
    print(jane.email)
    print(jane.score)

    #Change name from Jane to Janet
    jane.name = "Janet"
    print(jane.name)
    #Change private attribute score from 5 to 3 
    jane.score = 3
    print(jane.score)
    #Delete the score
    del jane.score
    #print(jane.score) # shoulf produce AttributeError

    Student.show_short_ver_of_uni_name()

    joe = Student.createfrom_str("Joe_4")
    print(joe.name, joe.score, joe.email)

    joe.print_full_info()

    #print(Student.return_score_by_percentage(1,10))





