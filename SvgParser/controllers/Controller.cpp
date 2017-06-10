#include "Controller.h"
#include "../shapes/Rect.h"
#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

static const char* const values[] = {"rect", "cyrcle", "line"};

Controller::Controller()
{

}

vector<Shape*> Controller::openAndReadSvgFile(string fileName)
{
    ifstream svg;
    //As mentioned here https://stackoverflow.com/questions/10966446/passing-a-string-to-file-open
    svg.open(fileName.c_str());
    if (svg.is_open())
    {
        cout<<"inside"<<endl;
        for(string line; getline(svg, line);){
            Shape* shape = craeteShapeObject(line);
            if(shape->getValid()){
                shapes.push_back(shape);
            }
        }
    }
    svg.close();
    cout<<shapes.size()<<endl;
    return shapes;
}

Shape* Controller::craeteShapeObject(string svgObject){
    if(svgObject.find(values[0])!= string::npos){
        Rect* rect = new Rect(svgObject);
        return rect;
    }
    return new Rect("");
}

void Controller::printShapes(){
    for(int i = 0; i<shapes.size(); i++){
        //cout<<shapes[i]->getName()<<" "<<shapes[i]->getFillColor()<<endl;
        cout<<shapes[i];
    }
}