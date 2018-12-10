#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_SHAPE_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_SHAPE_H


class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}
    virtual double getArea() const = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : m_w(w), m_h(h) {}
    virtual ~Rectangle() {}
    virtual double getArea() const { return m_w * m_h; }
private:
    double m_w, m_h;
};

//Rectangle* rectPt( new Rectangle(22.2, 11.1) );
//Shape* shapePt(rectPt); // Compiles and works well

//
//shared_ptr<Rectangle> rectSPt( new Rectangle(22.2, 11.1) );
//shared_ptr<Shape> shapePt = dynamic_pointer_cast<Shape>(rectSPt);




//shared_ptr<Person> personSpt( new Person("Kyle") );
//shared_ptr<Shape> shapeSPt = static_pointer_cast<Shape>(personSpt);

//shared_ptr<Shape> shapeSPt(personSpt); // Should never compile

#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_HODAYAMAR_SHAPE_H
