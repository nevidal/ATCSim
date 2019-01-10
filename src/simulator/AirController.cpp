/*
 * AirController.cpp
 *
 *  Created on: 21/07/2014
 *      Author: paco
 *
 *  Copyright 2014 Francisco Martín
 *
 *  This file is part of ATCSim.
 *
 *  ATCSim is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ATCSim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ATCSim.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AirController.h"
#include "Airport.h"
#include "Flight.h"
#include "Position.h"
#include <list>
#include <fstream>

namespace atcsim {

AirController::AirController() {
  // TODO(my_username): Auto-generated constructor stub
}
AirController::~AirController() {
  // TODO(my_username): Auto-generated destructor stub
}
void
AirController::doWork() {
  std::list<Flight*> flights = Airport::getInstance()->getFlights();
  std::list<Flight*>::iterator it;

  Position pos0(3500.0, 0.0, 1000.0);
  Position pos1(1500.0, 0.0, 500.0);
  Position pos2(200.0, 0.0, 25.0);
  Position pos3(-750.0, 0.0, 25.0);

// Puntos del recorrido auxiliar 1 recorrido rectangular espiral
  Position aux1_0(10000.0, 13500.0, 2000.0);
  Position aux1_1(10000.0, 3000.0, 1800.0);
  Position aux1_2(5000.0, 3000.0, 1600.0);
  Position aux1_3(5000.0, 13500.0, 1400.0);
  Position aux1_4(10000.0, 13500.0, 1200.0);
  Position aux1_5(10000.0, 3000.0, 1000.0);
  Position aux1_6(5000.0, 3000.0, 800.0);
  Position aux1_7(5000.0, 13500.0, 600.0);
  Position aux1_8(10000.0, 13500.0, 400.0);
  Position aux1_9(10000.0, 3000.0, 200.0);


// Puntos recorido auxiliar 2 --> "simetrico/espejo" al recorrido 1 espiral
  Position aux2_0(10000.0, -13500.0, 2000.0);
  Position aux2_1(10000.0, -3000.0, 1800.0);
  Position aux2_2(5000.0, -3000.0, 1600.0);
  Position aux2_3(5000.0, -13500.0, 1400.0);
  Position aux2_4(10000.0, -13500.0, 1200.0);
  Position aux2_5(10000.0, -3000.0, 1000.0);
  Position aux2_6(5000.0, -3000.0, 800.0);
  Position aux2_7(5000.0, -13500.0, 600.0);
  Position aux2_8(10000.0, -13500.0, 400.0);
  Position aux2_9(10000.0, -3000.0, 200.0);


// Rutas
  Route aterriza_0, aterriza_1, aterriza_2, aterriza_3;
  Route recorridoaux1_0, recorridoaux1_1, recorridoaux1_2, recorridoaux1_3,
  recorridoaux1_4, recorridoaux1_5, recorridoaux1_6, recorridoaux1_7,
  recorridoaux1_8, recorridoaux1_9;
  Route recorridoaux2_0, recorridoaux2_1, recorridoaux2_2, recorridoaux2_3,
  recorridoaux2_4, recorridoaux2_5, recorridoaux2_6, recorridoaux2_7,
  recorridoaux2_8, recorridoaux2_9;

// Definicion de recorridos
  aterriza_0.pos = pos0;
  aterriza_0.speed = 150.0;
  aterriza_1.pos = pos1;
  aterriza_1.speed = 100.0;
  aterriza_2.pos = pos2;
  aterriza_2.speed = 70.0;
  aterriza_3.pos = pos3;
  aterriza_3.speed = 10.0;

  recorridoaux1_0.pos = aux1_0;
  recorridoaux1_0.speed = 150.0;
  recorridoaux1_1.pos = aux1_1;
  recorridoaux1_1.speed = 150.0;
  recorridoaux1_2.pos = aux1_2;
  recorridoaux1_2.speed = 150.0;
  recorridoaux1_3.pos = aux1_3;
  recorridoaux1_3.speed = 150.0;
  recorridoaux1_4.pos = aux1_4;
  recorridoaux1_4.speed = 150.0;
  recorridoaux1_5.pos = aux1_5;
  recorridoaux1_5.speed = 150.0;
  recorridoaux1_6.pos = aux1_6;
  recorridoaux1_6.speed = 150.0;
  recorridoaux1_7.pos = aux1_7;
  recorridoaux1_7.speed = 150.0;
  recorridoaux1_8.pos = aux1_8;
  recorridoaux1_8.speed = 150.0;
  recorridoaux1_9.pos = aux1_9;
  recorridoaux1_9.speed = 150.0;

  recorridoaux2_0.pos = aux2_0;
  recorridoaux2_0.speed = 150.0;
  recorridoaux2_1.pos = aux2_1;
  recorridoaux2_1.speed = 150.0;
  recorridoaux2_2.pos = aux2_2;
  recorridoaux2_2.speed = 150.0;
  recorridoaux2_3.pos = aux2_3;
  recorridoaux2_3.speed = 150.0;
  recorridoaux2_4.pos = aux2_4;
  recorridoaux2_4.speed = 150.0;
  recorridoaux2_5.pos = aux2_5;
  recorridoaux2_5.speed = 150.0;
  recorridoaux2_6.pos = aux2_6;
  recorridoaux2_6.speed = 150.0;
  recorridoaux2_7.pos = aux2_7;
  recorridoaux2_7.speed = 150.0;
  recorridoaux2_8.pos = aux2_8;
  recorridoaux2_8.speed = 150.0;
  recorridoaux2_9.pos = aux2_9;
  recorridoaux2_9.speed = 150.0;


  it = flights.begin();
  if(!Airport::getInstance()->is_booked_landing()) {
    (*it)->getRoute()->clear();
  }

for(it = flights.begin(); it != flights.end(); ++it) {
  if ((*it)->getRoute()->empty()) {
    if((*it)->getPosition().get_y() >= 0 && Airport::getInstance()->is_booked_landing() == true){
       (*it)->getRoute()->push_back(recorridoaux1_0);
       (*it)->getRoute()->push_back(recorridoaux1_1);
       (*it)->getRoute()->push_back(recorridoaux1_2);
       (*it)->getRoute()->push_back(recorridoaux1_3);
       (*it)->getRoute()->push_back(recorridoaux1_4);
       (*it)->getRoute()->push_back(recorridoaux1_5);
       (*it)->getRoute()->push_back(recorridoaux1_6);
       (*it)->getRoute()->push_back(recorridoaux1_7);
       (*it)->getRoute()->push_back(recorridoaux1_8);
       (*it)->getRoute()->push_back(recorridoaux1_9);
    }else if((*it)->getPosition().get_y() <= 0 && Airport::getInstance()->is_booked_landing() == true){
      (*it)->getRoute()->push_back(recorridoaux2_0);
      (*it)->getRoute()->push_back(recorridoaux2_1);
      (*it)->getRoute()->push_back(recorridoaux2_2);
      (*it)->getRoute()->push_back(recorridoaux2_3);
      (*it)->getRoute()->push_back(recorridoaux2_4);
      (*it)->getRoute()->push_back(recorridoaux2_5);
      (*it)->getRoute()->push_back(recorridoaux2_6);
      (*it)->getRoute()->push_back(recorridoaux2_7);
      (*it)->getRoute()->push_back(recorridoaux2_8);
      (*it)->getRoute()->push_back(recorridoaux2_9);
    }else{
      Airport::getInstance()->book_landing();
      (*it)->getRoute()->push_back(aterriza_0);
      (*it)->getRoute()->push_back(aterriza_1);
      (*it)->getRoute()->push_back(aterriza_2);
      (*it)->getRoute()->push_back(aterriza_3);
    }
  }
}
}
}  // namespace atcsim
