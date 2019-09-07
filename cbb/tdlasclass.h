#ifndef TDLASCLASS_H
#define TDLASCLASS_H


class TDLASclass
{
public:
    TDLASclass();

    int dim();
    int LOS();
private:
    int numLOS=60;
    int N=20;

};

#endif // TDLASCLASS_H
