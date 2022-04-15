

class almondjoy{    
    public:
        void almondjoy(std::string name, std::vector<Ingredient>* ingredientList);

        virtual std::string getName() = 0;
        virtual std::vector<Ingredient>* getIngredients() = 0;

    private:
        std::string name;
        std::vector<Ingredient>* ingreds;
};