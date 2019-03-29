//
// Created by enka on 27.03.19.
//

#ifndef PATTERNS_BUILDINGS_H
#define PATTERNS_BUILDINGS_H
const int FullStr = 50;

class WarBuild{
public:
    virtual double protect() const = 0;
    virtual void damage(int d) = 0;
    virtual void increaselevel() = 0;
    virtual int getlevel() const = 0;
    virtual int strength() const = 0;
    virtual int price() const = 0;
    virtual ~WarBuild() = default;
};

class Moat:public WarBuild{ //дописать описание!!
public:
    Moat(int level);

    double protect() const override;
    void damage(int d) override;
    void increaselevel() override;
    int getlevel() const override;
    int strength() const override;
    int price() const override;
    ~Moat() override;
private:
    int strength_;
    int level_;
    int price_;
};

class Wall:public WarBuild{
public:
    Wall(int level);

    double protect() const override;
    void damage(int d) override;
    void increaselevel() override;
    int getlevel() const override;
    int strength() const override;
    int price() const override;
    ~Wall() override;
private:
    int strength_;
    int level_;
    int price_;
};
//_________________________________________________________//
class EconomicBuild{
public:
    virtual int tax() const = 0;
    virtual void increaselevel() = 0;
    virtual int getlevel() const = 0;
    virtual int price()const  = 0;
    virtual void expand() = 0;
    virtual ~EconomicBuild() = default;
};
class Market: public EconomicBuild{
public:
    Market(int level);
    int tax() const override;
    void increaselevel() override;
    int getlevel() const override;
    int price()const override;
    void expand() override;
    ~Market() override;
private:
    int tax_;
    int level_;
    int price_;
    int sellerNum ;
};
//_________________________________________________________//

class SocialBuild{
public:
    virtual int happiness() const = 0;
    virtual void increaselevel() = 0;
    virtual int getlevel() const = 0;
    virtual int price()const  = 0;
    virtual void repair() = 0;
    virtual void amortization() = 0;
    virtual int strength() = 0;
    virtual ~SocialBuild() = default;
};

class Hospital:public SocialBuild{
public:
    Hospital(int level);
    int happiness() const override;
    void increaselevel() override;
    int getlevel() const override;
    int price()const  override;
    void repair() override;
    void amortization() override;
    int strength() override;
    ~Hospital() override;
private:
    int happiness_;
    int level_;
    int price_;
    int strength_;
};

class Church:public SocialBuild{
public:
    Church(int level);
    int happiness() const override;
    void increaselevel() override;
    int getlevel() const override;
    int price()const  override;
    void repair() override;
    void amortization() override;
    int strength() override;
    ~Church() override;
private:
    int happiness_;
    int level_;
    int price_;
    int strength_;
};

#endif //PATTERNS_BUILDINGS_H
