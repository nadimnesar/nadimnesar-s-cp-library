double line_segment(point a, point b, point c, point d, double m1, double m2){
    double x1 = (((distance(a, b) - m1) * a.x) + (m1 * b.x))/distance(a, b);
    double y1 = (((distance(a, b) - m1) * a.y) + (m1 * b.y))/distance(a, b);

    double x2 = (((distance(c, d) - m2) * c.x) + (m2 * d.x))/distance(c, d);
    double y2 = (((distance(c, d) - m2) * c.y) + (m2 * d.y))/distance(c, d);

    point p, q;
    p.x = x1; p.y = y1;
    q.x = x2; q.y = y2;

    return distance(p, q);
}