int Vin = 5;                      // source voltage

int raw1,                         // raw values from the arduino
    raw2,
    raw3;

float Vout1,                      // voltage drop between each of the resistors
      Vout2,
      Vout3;

float R0 = 1800,                   // known resistor

      R1,                         // resistance values of the resistors
      R2,
      R3;

float out12 = 0,                 // values after the delta-to-wye transform
      out23 = 0,
      out13 = 0,
      Rsum = 0;

void setup()
{
  Serial.begin( 9600 );
}

void loop()
{
  raw1 = analogRead( A0 );                    // value from 0 to 1023
  raw2 = analogRead( A1 );
  raw3 = analogRead( A2 );
  
  Vout1 = ( raw1 / 1024.0 )*Vin;              // calculating the actual voltage
  Vout2 = ( raw2 / 1024.0 )*Vin;
  Vout3 = ( raw3 / 1024.0 )*Vin;

  R1 = R0 * ( ( Vout2/Vout1 ) - 1 );          // revised voltage divider
  R2 = R0 * ( ( Vout3/Vout1 ) - 1 ) - R1;
  R3 = R0 * ( ( Vin/Vout1 ) - 1 ) - R1 - R2;

  Rsum = R1 + R2 + R3;                        // delta to wye formulas
  out12 = ( R1 * R2 )/Rsum;
  out23 = ( R2 * R3 )/Rsum;
  out13 = ( R1 * R3 )/Rsum;

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  
  Serial.print( "Rab: " );
  Serial.println( R1 );
  Serial.print( "Rbc: " );
  Serial.println( R2 );
  Serial.print( "Rac: " );
  Serial.println( R3 );
  
  Serial.println();
  
  Serial.print( "Ra: " );
  Serial.println( out13 );
  Serial.print( "Rb: " );
  Serial.println( out12 );
  Serial.print( "Rc: " );
  Serial.println( out23 );
  
  delay( 1000 );

}
