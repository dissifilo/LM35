    #include<math.h>
    
    const int lm35Pin = 0; //pin A0 to LM35 V-out
    
    //current temperature
    float CTemp;
    /*change "float" to "int" declaration for no small numbers*/
    
    //LM35 detection
    double Thermister(int RawADC) {
    CTemp = (5.0 * RawADC * 100.0)/1024.0;  //compute data to centigrade
    //CTemp = (cel*9)/5 + 32; <--- uncomment for farenhite 
    return CTemp;
    }
    
    void setup() {
    Serial.begin (9600); //set 9600 bps
    }
    
    void loop() {
      
    CTemp = Thermister(analogRead(lm35Pin)); //read tempr. from LM35
    Serial.println("Current temperature is ");
    Serial.print("現在溫度為");
    Serial.print(CTemp);
    Serial.println("°C"); //or °F
    Serial.println(" "); //separation for easy read
    delay(1000); //display per second
    
    }
