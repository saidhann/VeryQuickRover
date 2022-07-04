#include "ConvexHull.h"
double max(double first, double second, double third, double forth) {
    double maximum = first;
    if(maximum<second) maximum = second;
    if(maximum<third) maximum = third;
    if(maximum<forth) maximum = forth;
    return maximum;
}
double min(double first, double second, double third, double forth) {
    double maximum = first;
    if(maximum>second) maximum = second;
    if(maximum>third) maximum = third;
    if(maximum>forth) maximum = forth;
    return maximum;
}

bool notIntersect(ConvexHull const& left, ConvexHull const& right) noexcept {
    int sizeleft = left.vectors.size();
    int sizeright = right.vectors.size();
   /* std::cout<<"IlVc: "<<left.vectors.size()<<std::endl;
    std::cout<<"Lewy: "<<left.vectors[0]<<"\n";
    std::cout<<left.vectors[1]<<"\n";
    std::cout<<left.vectors[2]<<"\n";
    std::cout<<left.vectors[3]<<"\n";
    std::cout<<"Prawy: "<<right.vectors[0]<<"\n";
    std::cout<<right.vectors[1]<<"\n";
    std::cout<<right.vectors[2]<<"\n";
    std::cout<<right.vectors[3]<<"\n";*/

   /* Vector3D tempLeft[4],temoRight[4];
    tempLeft[0] = leftvectors[1];
    tempLeft[1] = leftvectors[3];
    tempLeft[2] = leftvectors[5];
    tempLeft[3] = leftvectors[6];

    tempright[0] = rightvectors[1];
    tempright[1] = rightvectors[3];
    tempright[2] = rightvectors[5];
    tempright[3] = rightvectors[6];*/
/*
    double leftMaxX;
    double leftMinX;
    double leftMinY;
    double leftMaxY;

    double rightMinX ;
    double rightMaxX ;
    double rightMinY ;
    double rightMaxY ;

    leftMaxX=tempLeft[0][0];
    leftMinX=tempLeft[0][0];
    leftMinY=tempLeft[0][1];
    leftMaxY=tempLeft[0][1];

    rightMaxX=tempRight[0][0];
    rightMinX=tempRight[0][0];
    rightMinY=tempRight[0][1];
    rightMaxY=tempRight[0][1];

    for(int i = 0;i<4;i++) {
        if(leftMaxX<tempLeft[i][0]) leftMaxX=tempLeft[i][0];
        if(leftMaxY<tempLeft[i][0]) leftMaxY=tempLeft[i][0];
        if(rightMaxX<tempLeft[i][0]) leftMaxX=tempLeft[i][0];
        if(leftMaxX<tempLeft[i][0]) leftMaxX=tempLeft[i][0];
    }*/
    double leftMinX = min(left.vectors[sizeleft-23][0],left.vectors[sizeleft-22][0],left.vectors[sizeleft-19][0],left.vectors[sizeleft-18][0]);
    double leftMaxX = max(left.vectors[sizeleft-23][0],left.vectors[sizeleft-22][0],left.vectors[sizeleft-19][0],left.vectors[sizeleft-18][0]);
    double leftMinY = min(left.vectors[sizeleft-23][1],left.vectors[sizeleft-22][1],left.vectors[sizeleft-19][1],left.vectors[sizeleft-18][1]);
    double leftMaxY = max(left.vectors[sizeleft-23][1],left.vectors[sizeleft-22][1],left.vectors[sizeleft-19][1],left.vectors[sizeleft-18][1]);

    double rightMinX = min(right.vectors[sizeright-23][0],right.vectors[sizeright-22][0],right.vectors[sizeright-19][0],right.vectors[sizeright-18][0]);
    double rightMaxX = max(right.vectors[sizeright-23][0],right.vectors[sizeright-22][0],right.vectors[sizeright-19][0],right.vectors[sizeright-18][0]);
    double rightMinY = min(right.vectors[sizeright-23][1],right.vectors[sizeright-22][1],right.vectors[sizeright-19][1],right.vectors[sizeright-18][1]);
    double rightMaxY = max(right.vectors[sizeright-23][1],right.vectors[sizeright-22][1],right.vectors[sizeright-19][1],right.vectors[sizeright-18][1]);

    return (rightMaxX >leftMaxX&&leftMaxX > rightMinX && rightMinY< leftMinY&&leftMinY < rightMaxY)
    ||(rightMinX < leftMaxX&&leftMaxX < rightMaxX && rightMaxY> leftMaxY&&leftMaxY > rightMinY)
    ||(rightMinX<leftMinX&&leftMinX < rightMaxX &&rightMaxY> leftMinY&&leftMinY > rightMinY)
    ||(rightMaxX >leftMinX&&leftMinX > rightMinX && rightMinY< leftMaxY&&leftMaxY < rightMaxY);
}
