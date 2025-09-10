#pragma once
class Appliance {
private:
    int  powerRating;
    bool isOn;
public:
    Appliance();
    explicit Appliance(int powerRating);
    virtual ~Appliance() = default;        

    void set_powerRating(int power);
    int  get_powerRating() const;
    void set_isOn(bool on);
    bool get_isOn() const;
    void turnOn();
    void turnOff();
    virtual double getPowerConsumption() const;
};
