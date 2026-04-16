#include <iostream>
using namespace std;

class Question {   // Question Class
private:
    string questionText;
    string options[4];
    int correctAnswer;

public:
    Question() {}  // Default constructor

    Question(string q, string opt[], int ans) {
        questionText = q;
        for (int i = 0; i < 4; i++) {
            options[i] = opt[i];
        }
        correctAnswer = ans;
    }

    void display() {
        cout << "\n" << questionText << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(int userAnswer) {
        return userAnswer == correctAnswer;
    }
};

class Quiz {    // Quiz Class
private:
    Question questions[3];
    int score;
    int count;

public:
    Quiz() {
        score = 0;
        count = 0;
    }

    void addQuestion(Question q) {
        if (count < 3) {
            questions[count] = q;
            count++;
        }
    }

    void startQuiz() {
        int answer;
        for (int i = 0; i < count; i++) {
            questions[i].display();
            cout << "Enter your answer (1-4): ";
            cin >> answer;

            if (questions[i].checkAnswer(answer)) {
                cout << "Correct!\n";
                score++;
            } else {
                cout << "Wrong!\n";
            }
        }
    }

    void showResult() {
        cout << "\nYour Score: " << score << "/" << count << endl;
        cout << "*********************************\n" << endl;
    }
};

class User {    // User Class
private:
    string name;

public:
    void start() {
        cout << "\n*********************************" << endl;
        cout << "Enter your name: ";
        cin >> name;

        Quiz quiz;

        string opt1[] = {"Paris", "London", "Berlin", "Rome"};
        quiz.addQuestion(Question("What is the capital of France?", opt1, 1));

        string opt2[] = {"3", "4", "5", "6"};
        quiz.addQuestion(Question("2 + 2 = ?", opt2, 2));

        string opt3[] = {"Earth", "Mars", "Jupiter", "Saturn"};
        quiz.addQuestion(Question("Largest planet?", opt3, 3));

        quiz.startQuiz();
        quiz.showResult();
    }
};

int main() {  // Main Function
    User user;
    user.start();
    return 0;
}