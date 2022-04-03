#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

enum action
{
	ADD = 1,
	SUBSTRACT,
	SCALE,
	LENGTH,
	NORMALIZE,
	COUNT_ACTION = 5
};

struct Vector
{
	double x = 0;
	double y = 0;
};

Vector tmpVector();

Vector add(Vector vec1, Vector vec2);

Vector substract(Vector vec1, Vector vec2);

Vector scale(Vector vec, double scalar);

double length(Vector vec);

Vector normalize(Vector vec);

double enterDouble();

int main()
{
    
    int answer;

    std::cout << "Choose one of the actions from 1 to 5:" << std::endl;
    std::cout << ADD << ". add;" << std::endl;
    std::cout << SUBSTRACT << ". substract;" << std::endl;
    std::cout << SCALE << ". scale;" << std::endl;
    std::cout << LENGTH << ". length;" << std::endl;
    std::cout << NORMALIZE << ". normalize;" << std::endl;

    std::cin >> answer;
        
    switch (answer)
    {
        case 1:
        {
            std::system("cls");
            std::cout << "Enter the first term" << std::endl;
            Vector vec1 = tmpVector();
            std::system("cls");
            std::cout << "Enter second term" << std::endl;
            Vector vec2 = tmpVector();
        
            Vector result = add(vec1, vec2);
        
            std::system("cls");
            std::cout << "Vector (" << vec1.x << ", " << vec1.y << ") plus vector (" << vec2.x << ", " << vec2.y << ")" << std::endl;
            std::cout << "Result: vector (" << result.x << ", " << result.y << ")" << std::endl << std::endl;
            break;
        }
        case 2:
        {
            std::system("cls");
            std::cout << "Enter minuend term" << std::endl;
            Vector vec1 = tmpVector();
            std::system("cls");
            std::cout << "Enter subtrahend term" << std::endl;
            Vector vec2 = tmpVector();
        
            Vector result = substract(vec1, vec2);
        
            std::system("cls");
            std::cout << "Vector (" << vec1.x << ", " << vec1.y << ") minus vector (" << vec2.x << ", " << vec2.y << ")" << std::endl;
            std::cout << "Result: vector (" << result.x << ", " << result.y << ")" << std::endl << std::endl;
            break;
        }
        case 3:
        {
            std::system("cls");
            std::cout << "Enter vector" << std::endl;
            Vector vec = tmpVector();
            std::system("cls");
            std::cout << "Enter scalar" << std::endl;
            double scalar = enterDouble();
        
            Vector result = scale(vec, scalar);
        
            std::system("cls");
            std::cout << "Vector (" << vec.x << ", " << vec.y << ") multiply scalar " << scalar << std::endl;
            std::cout << "Result: vector (" << result.x << ", " << result.y << ")" << std::endl << std::endl;
            break;
        }
        case 4:
        {
            std::system("cls");
            std::cout << "Enter vector" << std::endl;
            Vector vec = tmpVector();
            
            double vecLength = length(vec);
            
            std::system("cls");
            std::cout << "Vector length(" << vec.x << ", " << vec.y << ") " << std::endl;
            std::cout << "Result: " << vecLength << std::endl << std::endl;
            break;
        }
        case 5:
        {
            std::system("cls");
            std::cout << "Enter vector" << std::endl;
            Vector vec = tmpVector();
        
            Vector result = normalize(vec);
        
            std::system("cls");
            std::cout << "Normalize vector (" << vec.x << ", " << vec.y << ")" << std::endl;
            std::cout << "Result: vector (" << result.x << ", " << result.y << ")" << std::endl << std::endl;
            break;
        }
    }   
}

Vector tmpVector()
{
    Vector vec;

    std::cout << "Enter vector coordinates X, Y: ";
    vec.x = enterDouble();
    vec.y = enterDouble();

    return vec;
}

Vector add(Vector vec1, Vector vec2)
{
    Vector result;
    result.x = vec1.x + vec2.x;
    result.y = vec1.y + vec2.y;

    return result;
}

Vector substract(Vector vec1, Vector vec2)
{
    Vector result;
    result.x = vec1.x - vec2.x;
    result.y = vec1.y - vec2.y;

    return result;
}

Vector scale(Vector vec, double scalar)
{
    Vector result;
    result.x = vec.x * scalar;
    result.y = vec.y * scalar;

    return result;
}

double length(Vector vec)
{
    return (std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2)));
}

Vector normalize(Vector vec)
{
    double vecLength = length(vec);

    Vector result;
    result.x = vec.x / vecLength;
    result.y = vec.y / vecLength;

    return result;
}

double enterDouble()
{
    std::string tmp;
    bool error;

    do
    {
        error = false;
        bool dot = false;
        std::cin >> tmp;

        for (int i = 0; (i < tmp.length()) && !error; ++i) 
        {
            if ((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '.' || tmp[i] == '-')
            {
                if (tmp[i] == '.')
                    (dot ? error = true : dot = true);
                else
                    if (tmp[i] == '-' && i != 0)
                        error = true;
            }
            else
                error = true;
        }
        if (error)std::cout << "ERROR!Incorrect coordinates.Try again" << std::endl;        
    } while (error);

    return (std::stod(tmp));
}