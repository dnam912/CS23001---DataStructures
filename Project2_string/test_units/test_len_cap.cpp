// String Test Program
// 
// Tests:  len_cap , uses length(), capacity()
//
//  
#include <iostream> 
#include <cassert>
#include "string.hpp"


//===========================================================================
int main ()
{

    // If STRING_SIZE is 256 in global constant, 
    // CAPACIY will be 255 (STRING_SIZE - 1)

    { 
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;
        //------------------------------------------------------
        // SETUP FIXTURE

        String str = "abcdefghijklmnopqrstuvwxyz"; // 26
        
        // TEST
        int length_ = str.length(); // 26
        int capacity_ = str.capacity(); 

        // VERIFY
        assert(length_    == 26);

        std::cout << "Words: " << str << std::endl;
        std::cout << "Length: " << length_ << std::endl;
        std::cout << "Capacity(STRING_SIZE - 1): " << capacity_ << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;
        //------------------------------------------------------
        // SETUP FIXTURE

        String str;
        
        // TEST
        int length_ = str.length(); // 0
        int capacity_ = str.capacity(); 

        // VERIFY
        assert(length_    == 0);

        std::cout << "Words: " << str << std::endl;
        std::cout << "Length: " << length_ << std::endl;
        std::cout << "Capacity(STRING_SIZE - 1): " << capacity_ << std::endl;
    }


    {
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;
        //------------------------------------------------------
        // SETUP FIXTURE
        char X = 'X';
        String str(X);
        
        // TEST
        int length_ = str.length(); // 1
        int capacity_ = str.capacity(); 

        // VERIFY
        assert(length_    == 1);

        std::cout << "Words: " << str << std::endl;
        std::cout << "Length: " << length_ << std::endl;
        std::cout << "Capacity(STRING_SIZE - 1): " << capacity_ << std::endl;
    }
    
    // ****** REVISE ****** //
    {
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;
        //------------------------------------------------------
        // SETUP FIXTURE

        // char X[12] = {'h','e','l','l','o',' ','w','o','r','l','d', '\0'};
        char X[] = {"hello world"};
        // "0" or 0
        // "" --> null 
        String str(X);

        // TEST
        int length_ = str.length(); // 11
        std::cout << "length_: " << length_ << std::endl;
        int capacity_ = str.capacity(); 

        // VERIFY
        assert(length_    == 11);
        //assert(capacity_ == 11); //

        std::cout << "Words: " << str << std::endl;
        std::cout << "Length: " << length_ << std::endl;
        std::cout << "str[9]:" << str[9] << std::endl;
        std::cout << "str[10]:" << str[10] << std::endl;
        std::cout << "str[11]:" << str[11] << std::endl;
        std::cout << "Capacity(STRING_SIZE - 1): " << capacity_ << std::endl;
    }


    {
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;
        //------------------------------------------------------
        // SETUP FIXTURE

        String str("Digital Innovation and Technology Services seeks a tech-savvy student to collaborate with museum staff on outward-facing digital projects at the museum, including the museum’s website and ongoing digital projects.");

        // TEST
        int length_ = str.length();
        int capacity_ = str.capacity(); 

        // VERIFY
        assert(length_    == 215);
        //assert(capacity_ == 255); //

        std::cout << "Words: " << str << std::endl;
        std::cout << "Length: " << length_ << std::endl;
        std::cout << "Capacity(STRING_SIZE - 1): " << capacity_ << std::endl;
    }


    // WHY ISN'T ERROR DETECTED IN THIS STRING EVEN CHARACTERS ARE OVER CAPACITY? 
    // IS THAT BECAUSE C++ DOENS'T CHECK ARRAY BOUNDS?
    {
        std::cout << std::endl;
        std::cout << "========== ========= ========== ==========" << std::endl;
        //------------------------------------------------------
        // SETUP FIXTURE

        String str("The Digital Projects Intern will learn the basics of project management while assisting with tasks including: work on upcoming projects including ArtLens Gallery, supporting the museum’s newly redesigned website, testing software for digital projects, writing detailed testing reports and documentation, writing copy for website and social on digital initiatives, supporting additional outward facing projects as they arise, and may include occasional time spent in the ArtLens Gallery interacting with visitors and assisting with technology. The intern will have the opportunity to generate content for outward-facing collection-based toolsets. They will also have the opportunity to work on themes for the ArtLens Wall, ArtLens App, and ArtLens Studio’s Zoom & Reveal Wall.");

        // TEST
        int length_ = str.length();
        int capacity_ = str.capacity(); 

        // VERIFY
        assert(length_    == 779);
        //assert(capacity_ == 255); //

        std::cout << "Words: " << str << std::endl;
        std::cout << "Length: " << length_ << std::endl;
        std::cout << "Capacity(STRING_SIZE - 1): " << capacity_ << " <-- If characters are more than CAPACITY and are out of array bounds, an error must be detected or claimed, but it wasn't" << std::endl;
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << std::endl;
    std::cout << "Done testing length and capacity." << std::endl;
    std::cout << std::endl;
    
    return 0;
}



