#include <iostream>

class Figure{
protected:
    std::string figure;
    int sides;
    std::string space = "\n";

public:
    Figure(){
        figure = "Фигура: ";
        sides = 0;
    }

public:
    virtual bool check(){
        if(sides == 0) {
            space = "\n\n";
            return true;
        }
        return false;
    }

    virtual void print_info(){
        bool right_or_not = check();
        std::cout << figure << "\n" << (right_or_not? "Правильная\n": "Неправильная\n")
        << "Количество сторон: " << this->sides << space;
        }
        void set_data(std::string figure, int sides){
            this->figure = figure;
            this->sides = sides;

    }

};
class Triangle:public Figure{
///    Треугольник:-> Прямоугольный треугольник
protected:
    int a, b, c;
    int A, B, C;

public:

    Triangle(int a, int b, int c, int A, int B, int C){
        this->a = a, this->b = b, this->c = c;
        this->A = A, this->B = B, this->C = C;
        set_data("Треугольник: ", 3);
    }

    bool check() override{
        if(sides == 3) {
            if (a + b + c > 0 && A + B + C == 180) {
                return true;
            }
        }
        return false;
    }

    void print_info () override{

        Figure::print_info();
        std::cout << "Стороны: a=" <<  a << " b=" << b << " c=" <<  c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class Rectangle_triangle: public Triangle{
///    Прямоугольный треугольник:-> Треугольник

public:
//    Rectangle_triangle(){
//        Figure("Прямоугольный треугольник:", 3);
//    }
    Rectangle_triangle(int a, int b, int c, int A, int B):
    Triangle(a, b, c, A, B, 90){
        set_data("Прямоугольный треугольник:", 3);
    }

    bool check() override{
        if(Triangle::check()) {
            if(C == 90) {
                return true;
            }
        }
        return false;
    }
};

class Triangle_two_sides_equal:public Triangle{
///    Равнобедренный треугольник:-> Равносторонний треугольник

public:
Triangle_two_sides_equal(int a, int b, int A, int B, int C):
Triangle(a, b, a, A, B, C){
    set_data("Равнобедренный треугольник:",3);
}
bool check() override{
    if(Triangle::check()){
        if(a == c && A == B) return true;
    }
    return false;
}
};

class Triangle_three_sides_equal:public Triangle_two_sides_equal{
///    Равносторонний треугольник:->Равнобедренный треугольник

public:
    Triangle_three_sides_equal(int a):
    Triangle_two_sides_equal(a, a, 60, 60, 60){
        set_data("Равносторонний треугольник:", 3);
    }
    bool check() override{
        if(Triangle::check()){
            if(a == b && a == b && A == 60 && B == 60 && C == 60)return true;
        }
        return false;
    }
};

class Quadrangle:public Figure{
    ///    Четырёхугольник:->параллелограмм

protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D){
        this->a = a, this->b = b, this->c = c, this->d = d;
        this->A = A, this->B = B, this->C = C, this->D = D;
        set_data("Четырёхугольник:", 4);
    }
    bool check() override{
        if(sides == 4){
            if(A + B + C + D == 360) return true;
        }
        return false;
    }

    void print_info() override{
        Figure::print_info();
        std::cout << "Стороны: a=" <<  a << " b=" << b << " c=" <<  c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }


};

class Parallelogram:public Quadrangle{
///    Параллелограмм:->четырехугольник->прямоугольник

public:
    Parallelogram(int a, int b, int A, int B):
    Quadrangle(a,b,a,b,A,B,A,B){
        set_data("Параллелограмм:", 4);
    }
    bool check() override{
        if(Quadrangle::check()){
            if(a == c && b == d && A == C && B == D) return true;
        }
        return false;
    }
};

class Rectangle:public Parallelogram{
///Прямоугольник:параллелограмм

public:
    Rectangle(int a, int b, int A): Parallelogram(a, b, A, A){
        set_data("Прямоугольник:", 4);
    }
    bool check() override{
        if(Quadrangle::check()){
            if(a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) return true;
        }
        return false;
    }
};

class Rhombus:public Parallelogram{
///    Ромб:->параллелограмм->квадрат

public:
    Rhombus(int a, int A, int B):Parallelogram(a, a, A, B){
        set_data("Ромб:", 4);
    }
    bool check( ) override{
        if(Quadrangle::check()){
            if(a == b && b == c && c == d && A == C && B == D) return true;
        }
        return false;
    }
};

class Square:public Rhombus{
///   Квадрат:->ромб

public:
    Square(int a, int A): Rhombus(a, A, A){
        set_data("Квадрат:", 4);
    }
    bool check() override{
        if(Quadrangle::check()){
            if(a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90) return true;
        }
        return false;
    }
};

void print(Figure& figure){
    figure.print_info();

}



int main() {
    Figure figure;
    print(figure);

    Triangle obj_triangle(10,20,30,50,60,70);
    print(obj_triangle);

    Rectangle_triangle obj_rectangle_triangle(10,20,30,50,60);
    print(obj_rectangle_triangle);

    Rectangle_triangle obj_rectangle_triangle1(10,20,30,50,40);
    print(obj_rectangle_triangle1);

    Triangle_two_sides_equal triangleTwoSidesEqual(10,20,50,60,50);
    print(triangleTwoSidesEqual);

    Triangle_three_sides_equal triangleThreeSidesEqual(30);
    print(triangleThreeSidesEqual);



    Quadrangle quadrangle(10,20,30,40,50,60,70,80);
    print(quadrangle);

    Parallelogram parallelogram(20,30,30,40);
    print(parallelogram);

    Rectangle rectangle(10,20,90);
    print(rectangle);

    Rhombus rhombus(30,30,40);
    print(rhombus);

    Square square(20,90);
    print(square);


    return 0;
}

