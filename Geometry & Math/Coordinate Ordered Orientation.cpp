double clock(double x1, double y1, double x2, double y2, double x3, double y3){
    return (((y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)) > EPS);    //slope of (p1, p2) > slope of (p2, p3)
}

bool oriention(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    return (clock(x1, y1, x2, y2, x3, y3) and clock(x2, y2, x3, y3, x4, y4) and clock(x3, y3, x4, y4, x1, y1) and clock(x4, y4, x1, y1, x2, y2));
}