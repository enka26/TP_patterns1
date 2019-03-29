//
// Created by enka on 27.03.19.
//

#ifndef PATTERNS_SQUADS_H
#define PATTERNS_SQUADS_H
//#include<map>

//using std::map; //What??

const int FullLife = 40;

class Squad
{
public:
    virtual void help() const = 0;
    virtual void increaselevel() = 0;
    virtual int getlevel() const = 0;
    virtual int life() const = 0;
    virtual void decreaseLife() = 0;
    virtual int price() const = 0;
    virtual int getProd(int rnd);
    virtual ~Squad() = default;
};

//-----------------------------------------------//

class Builders: public Squad{
public:
    Builders(int level);
    void help()const override;
    void increaselevel() override;
    int getlevel() const override;
    int life() const override;
    void decreaseLife() override;
    int price() const override;
    ~Builders() override;
private:
    int level_;
    int life_;
    int price_;
};

class Warriors: public Squad{
public:
    Warriors(int level);
    void help()const override;
    void increaselevel() override;
    int getlevel() const override;
    int life() const override;
    void decreaseLife() override;
    int price() const override;
    ~Warriors() override;
private:
    int level_;
    int life_;
    int price_;
};



//------------------------------------------//
class Peasants: public Squad{
public:

    Peasants(int level);
    void help()const override;
    void increaselevel() override;
    int getlevel() const override;
    int life() const override;
    void decreaseLife() override;
    int price() const override;
    int getProd(int rnd)const;
    ~Peasants() override;
private:
    int level_;
    int life_;
    int price_;
};


class Hunters: public Squad{
public:
    Hunters(int level);

    void help()const override;
    void increaselevel() override;
    int getlevel() const override;
    int life() const override;
    void decreaseLife() override;
    int price() const override;
    int getProd(int rnd) const;
    ~Hunters() override;
private:
    int level_;
    int life_;
    int price_;
};




#endif //PATTERNS_SQUADS_H
