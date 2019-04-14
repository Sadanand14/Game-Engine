	
	//The comments in the code section below are basically suggestions for optimizing the approach taken below to implement this code. 
	//I apologize for not knowing what a moderately smart compiler is able to optimize on its own and mentioning possibly trivial issues in the code.

	//However I feel the approach could be changed itself a little bit more to make this code perform better. 
	//As far as I can see, we are creating a Luminance object to simply perform a calculation using the same constants each time we call a new class object. 

	//It would be a lot better to simply implement a struct which stores the coefficient values as variables and has a method that takes in data from the 
	//ColorBuffer struct and does the same calculations that the Luminance object does using the coefficient data it stores.
	//We can define a single struct in CountDarkpixels (since were using the same data for all iterations) and then pass it to whichever functions actually make use of it.
	// This would save us from the cycles wasted on allocating and deallocating memory to a new object each function call.
	
	// "IF" the coefficient values are unlikely to change then
	// We could take this a step further and not even have a struct but simply a function that makes this calculation using hard-coded values of the coefficients
	// But I feel that may be going to far in the name of optimization.
	
	

	#define SCREEN_WIDTH (800)
	#define SCREEN_HEIGHT (600)
	int countDarkPixels(ColorBuffer cb)
	{
		int darkness = 0;
		for(int x = 0; x < SCREEN_WIDTH; x++)
		{
			for(int y = 0; y < SCREEN_HEIGHT; y++)
			{
				// it would save a lot of function call overhead if we were to save the value that getMax(cb) returns and use it in the body of 'else' to add to dark (line 43).
				if(getMax(cb) < 0)
				{
					return -1;
				}
				else
				{
					float dark = 0;

					// In the expression below, x and y need to be interchanged for the data to be accessed quickly by the cache
					// its currently using values at indices separated by SCREEN_WIDTH per iteration of the nested loop which means  
					// that the cache will miss and have to re-fetch data each iteration
					int index = y * SCREEN_WIDTH + x;
					dark += cb.red[index] / 255.0;
					dark += cb.green[index] / 255.0;
					dark += cb.blue[index] / 255.0;
					dark *= getMax(cb);
					dark /= 3;	

					// if the pixel is "dark" then add it to the darkness count
					if(dark < 32.0) darkness++;
				}
			}
		}
		return darkness;
	}

	float getMax(ColorBuffer cb)
	{
		float LMax = 0;
		for(int x = 0; x < SCREEN_WIDTH; x++)
		{
			for(int y = 0; y < SCREEN_HEIGHT; y++)
			{
				// In the expression below, x and y need to be interchanged for the data to be accessed quickly by the cache
				// its currently using values at indices separated by SCREEN_WIDTH per iteration of the nested loop which means  
				// that the cache will miss and have to re-fetch data each iteration
				int index = y * SCREEN_WIDTH + x;
												
				// if the condition turns out to be true, we are calling Compute Luminance twice to get the same value. It would be better to call ComputeLuminance once with those parameters
				// and then store the value it returns into a variable and use that variable in the expression below
				LMax = (ComputeLuminance(cb, index) > LMax) ? ComputeLuminance(cb, index) : LMax;
			}
		}
		return LMax;
	}

	int ComputeLuminance(ColorBuffer cb, int index)
	{
		int value = 0;
		int darknessScale = 2;
		Luminance* pCurrent = new Luminance(darknessScale);//should define Luminance object onto the stack and not the heap as you are deleting the object within this function anyway
		pCurrent->red = pCurrent->getRCoeff() * cb.red[index];
		pCurrent->green = pCurrent->getGCoeff() * cb.green[index];
		pCurrent->blue = pCurrent->getBCoeff() * cb.blue[index];
		value = pCurrent->getValue();
		delete pCurrent;// wouldn't have been needed if the object had been defined on stack
		return value;
	}

	class Luminance
	{
		//all the data and methods here are currently defaulted to private. 
		//for the way the code is currently laid out, the class needs the "public:" keyword to change the protection status of all the data and methods for the code to work at all
		// otherwise the ComputeLuminance method wont be able to access the member variables or methods of this class.
		
		// to avoid a ton of implicit truncation from float to int, we could make these integers to floats and preserve the precision.
		int blue;
		int green;
		int red;
		float scale;

		Luminance(float startingScale) { scale = startingScale;}//initializer list would have been better , also using the keyword "explicit" would be good here, to avoid future bugs.
		float getRCoeff() {return 0.30;}// inlining getters is always good to avoid function call overheads.
		float getGCoeff() {return 0.59;}
		float getBCoeff() {return 0.11;}
		int getValue(){return (red + green + blue) * scale;}// could instead return a float to avoid truncation to int and return float
	};

	struct ColorBuffer
	{
		// assuming that we are going to be pushing in the standard 0-255 values for each color channel, using a short int would be a better idea to half the memory for this structure
		unsigned int red[SCREEN_WIDTH * SCREEN_HEIGHT];
		unsigned int green[SCREEN_WIDTH * SCREEN_HEIGHT];
		unsigned int blue[SCREEN_WIDTH * SCREEN_HEIGHT];
	
		int size() {return SCREEN_WIDTH * SCREEN_HEIGHT;}// this method isn't even being used, plus the macros it uses are available globally.So  I'd say its unnecessary call overhead, if called.
	};

