#include <iostream>
#include <vector>
#include <iomanip>

class Course {
public:
    std::string name;
    double grade;
    int credits;

    Course(std::string n, double g, int c) : name(n), grade(g), credits(c) {}
};

class Student {
public:
    std::string name;
    std::vector<Course> courses;

    Student(std::string n) : name(n) {}

    void addCourse(std::string name, double grade, int credits) {
        courses.push_back(Course(name, grade, credits));
    }

    double calculateCGPA() {
        double totalGradePoints = 0;
        int totalCredits = 0;
        for (const auto& course : courses) {
            totalGradePoints += course.grade * course.credits;
            totalCredits += course.credits;
        }
        return (totalCredits == 0) ? 0 : totalGradePoints / totalCredits;
    }

    void displayGrades() {
        std::cout << "Grades for " << name << ":\n";
        for (const auto& course : courses) {
            std::cout << "Course: " << course.name << ", Grade: " << course.grade << ", Credits: " << course.credits << '\n';
        }
    }
};

int main() {
    Student student("Sara");

    int numCourses;
    std::cout << "Enter the number of courses: ";
    std::cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        std::string courseName;
        double grade;
        int credits;

        std::cout << "Enter course name: ";
        std::cin >> courseName;
        std::cout << "Enter grade for " << courseName << ": ";
        std::cin >> grade;
        std::cout << "Enter credits for " << courseName << ": ";
        std::cin >> credits;

        student.addCourse(courseName, grade, credits);
    }

    student.displayGrades();

    double cgpa = student.calculateCGPA();
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Cumulative Grade Point Average (CGPA): " << cgpa << '\n';

    return 0;
}
