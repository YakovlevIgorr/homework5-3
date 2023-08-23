#include <iostream>

class Figure{

    std::string figure;
    int sides;

public:
    Figure(){
        figure = "Фигура: ";
        sides = 0;
    }
    Figure(std::string figure, int sides){
        this-> figure = figure;
        this-> sides = sides;
    }
public:
    virtual bool check(){
        if(sides == 0) {
            return true;
        } else return false;
    }

    virtual void print_info(bool right_or_not){
        std::cout << figure << "\n" << (right_or_not? "Правильная\n": "Неправильная\n")
        << "Количество сторон: " << this->sides << "\n";

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
    }

    bool check() override{
        if(a + b + c > 0 && A + B + C == 180) {
            return true;
        }else return false;
    }

    void print_info (bool right_or_not) override{
        std::cout << "Стороны: a=" <<  a << " b=" << b << " c=" <<  c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class Rectangle_triangle: public Triangle{
///    Прямоугольный треугольник:-> Треугольник

public:
    Rectangle_triangle(int a, int b, int c, int A, int B):
    Triangle(a, b, c, A, B, 90){
    }
    bool check() override{
        if(A + B + C == 180) {
            return true;
        }else return false;
    }
};

class Triangle_two_sides_equal:public Triangle{
///    Равнобедренный треугольник:-> Равносторонний треугольник

public:
Triangle_two_sides_equal(int a, int b, int A, int B, int C):
Triangle(a, b, a, A, B, C){

}
};

class Triangle_three_sides_equal:public Triangle_two_sides_equal{
///    Равносторонний треугольник:->Равнобедренный треугольник

public:
    Triangle_three_sides_equal(int a):
    Triangle_two_sides_equal(a, a, 60, 60, 60){

    }
};

class Quadrangle{
    ///    Четырёхугольник:->параллелограмм

protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D){
        this->a = a, this->b = b, this->c = c, this->d = d;
        this->A = A, this->B = B, this->C = C, this->D = D;
    }

    void print_with_four_sides(std::string name_){
        std::cout << name_ << "\n";
        std::cout << "Стороны: a=" <<  a << " b=" << b << " c=" <<  c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }

};

class Parallelogram:public Quadrangle{
///    Параллелограмм:->четырехугольник->прямоугольник

public:
    Parallelogram(int a, int b, int A, int B):
    Quadrangle(a,b,a,b,A,B,A,B){

    }
};

class Rectangle:public Parallelogram{
///Прямоугольник:параллелограмм

public:
    Rectangle(int a, int b, int A): Parallelogram(a, b, A, A){

    }
};

class Rhombus:public Parallelogram{
///    Ромб:->параллелограмм->квадрат

public:
    Rhombus(int a, int A, int B):Parallelogram(a, a, A, B){

    }
};

class Square:public Rhombus{
///   Квадрат:->ромб

public:
    Square(int a, int A): Rhombus(a, A, A){

    }
};





int main() {
    Figure p;
    p.print_info(p.check());

     Figure obj_figure("Треугольник:",3);
     Triangle obj_triangle(10,20,30,50,60,70);
    Figure* f;
    Triangle* t;
    f = &obj_figure;
    t = &obj_triangle;

    f->print_info(t->check());
    t->print_info(t->check());

    Figure obj_figure1("Прямоугольный треугольник:",3);
    Rectangle_triangle obj_rectangle_triangle(10,20,30,50,60);
    Rectangle_triangle* rt;
    Figure* f1;
    f1 = &obj_figure1;
    rt = &obj_rectangle_triangle;
    f1->print_info(rt->check());
    rt->print_info(rt->check());

//
//    Rectangle_triangle rectangleTriangle(10,20,30,50,60);
//    rectangleTriangle.print("Прямоугольный треугольник:");
//
//    Triangle_two_sides_equal triangleTwoSidesEqual(10,20,50,60,50);
//    triangleTwoSidesEqual.print("Равнобедренный треугольник:");
//
//    Triangle_three_sides_equal triangleThreeSidesEqual(30);
//    triangleThreeSidesEqual.print("Равносторонний треугольник:");
//
//    Quadrangle quadrangle(10,20,30,40,50,60,70,80);
//    quadrangle.print_with_four_sides("Четырёхугольник:");
//
//    Parallelogram parallelogram(20,30,30,40);
//    parallelogram.print_with_four_sides("Параллелограмм:");
//
//    Rectangle rectangle(10,20,90);
//    rectangle.print_with_four_sides("Прямоугольник:");
//
//    Rhombus rhombus(30,30,40);
//    rhombus.print_with_four_sides("Ромб:");
//
//    Square square(20,90);
//    square.print_with_four_sides("Квадрат:");


    return 0;
}

