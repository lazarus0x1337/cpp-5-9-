// Required grades: sign 72, exec 45

class RobotomyRequestForm
{
private:
    
public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
