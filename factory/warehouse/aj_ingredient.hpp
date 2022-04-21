#include <string>


class Ingredient{
    public:
        void Ingredient(std::string name, int quantity, std::string path);
       // void Ingredient(std::string name, std::string path);

        virtual std::string getName() = 0;
        virtual std::string getPath() = 0;
        virtual int getQuantity() = 0;
        virtual void setQuantity(int quantity) = 0;

    private:
        std::string name;
        std::string path;
        int quantity = 0;
};
