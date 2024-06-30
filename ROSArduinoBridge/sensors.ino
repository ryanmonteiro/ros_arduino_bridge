#ifdef USE_SENSORS
    #include <VL53L0X.h>

    VL53L0X Sensor1;
    
    void initLaserSensors(){
        //Liga os sensores e altera seus endereços.
        //pinMode(XSHUT_Sensor1, INPUT); // Habilitar para usar o shutdown do sensor
        //delay(10);
        Sensor1.setAddress(Sensor1_endereco);
        
        //Inicializa os sensores.
        Sensor1.init();
      
        //Define timeout para os sensores.
        Sensor1.setTimeout(500);
    
        //Inicia o modo de leitura contínuo dos VL53L0X.
        Sensor1.startContinuous();
    }

    int readLaserSensors(){
        int measure1 = Sensor1.readRangeContinuousMillimeters();
        //return measure1;
        if ((measure1 > distanciaMin) && (measure1 <= distanciaMax)) {
            return measure1;
        }
        else {
            measure1 = 0;
            return measure1;
        }
    }

#endif