class ParkingSystem {
public:
    int big = 0 , medium = 0 , small = 0;
    
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        
        switch(carType) {
            case 1:
                return (big ? big-- , true : false);
            case 2:
                return (medium ? medium-- , true : false);
            default:
                return (small ? small-- , true : false);
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */