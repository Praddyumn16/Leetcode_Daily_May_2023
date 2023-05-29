class ParkingSystem {
public:
    int big = 0 , medium = 0 , small = 0;
    
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        
        bool ans;
        
        switch(carType) {
            case 1:
                ans = (big ? big-- , true : false);
                break;
            case 2:
                ans = (medium ? medium-- , true : false);
                break;
            default:
                ans = (small ? small-- , true : false);
                break;
        }
        
        return ans;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */