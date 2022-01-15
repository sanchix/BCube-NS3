#ifndef tStudent_h
#define tStudent_h

double tStudentInv(int grados_libertad, double probablidadDerecha);

double tStudentInv(int grados_libertad, double probablidadDerecha){
    
    double ret = -1;
    double probabilidadIzquierda = 1 - probablidadDerecha;
	
    if(grados_libertad == 1 && abs(probabilidadIzquierda - .9) < 0.00001){
		ret = 3.0776835;
	}
	else if(grados_libertad == 1 && abs(probabilidadIzquierda - .95) < 0.00001){
		ret = 6.3137515;
	}
	else if(grados_libertad == 1 && abs(probabilidadIzquierda - .975) < 0.00001){
		ret = 12.706205;
	}
	else if(grados_libertad == 1 && abs(probabilidadIzquierda - .99) < 0.00001){
		ret = 31.820516;
	}
	else if(grados_libertad == 1 && abs(probabilidadIzquierda - .995) < 0.00001){
		ret = 63.656741;
	}
	else if(grados_libertad == 1 && abs(probabilidadIzquierda - .9975) < 0.00001){
		ret = 127.32134;
	}
	else if(grados_libertad == 1 && abs(probabilidadIzquierda - .999) < 0.00001){
		ret = 318.30884;
	}
	else if(grados_libertad == 1 && abs(probabilidadIzquierda - .9995) < 0.00001){
		ret = 636.61925;
	}
	else if(grados_libertad == 1 && abs(probabilidadIzquierda - .99975) < 0.00001){
		ret = 1273.2393;
	}
	else if(grados_libertad == 1 && abs(probabilidadIzquierda - .9999) < 0.00001){
		ret = 3183.0988;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .9) < 0.00001){
		ret = 1.8856181;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .95) < 0.00001){
		ret = 2.9199856;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .975) < 0.00001){
		ret = 4.3026527;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .99) < 0.00001){
		ret = 6.9645567;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .995) < 0.00001){
		ret = 9.9248432;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .9975) < 0.00001){
		ret = 14.089047;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .999) < 0.00001){
		ret = 22.327125;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .9995) < 0.00001){
		ret = 31.599055;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .99975) < 0.00001){
		ret = 44.704587;
	}
	else if(grados_libertad == 2 && abs(probabilidadIzquierda - .9999) < 0.00001){
		ret = 70.700071;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .9) < 0.00001){
		ret = 1.6377444;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .95) < 0.00001){
		ret = 2.3533634;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .975) < 0.00001){
		ret = 3.1824463;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .99) < 0.00001){
		ret = 4.5407029;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .995) < 0.00001){
		ret = 5.8409093;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .9975) < 0.00001){
		ret = 7.4533185;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .999) < 0.00001){
		ret = 10.214532;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .9995) < 0.00001){
		ret = 12.923979;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .99975) < 0.00001){
		ret = 16.326335;
	}
	else if(grados_libertad == 3 && abs(probabilidadIzquierda - .9999) < 0.00001){
		ret = 22.203742;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .9) < 0.00001){
		ret = 1.5332063;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .95) < 0.00001){
		ret = 2.1318468;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .975) < 0.00001){
		ret = 2.7764451;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .99) < 0.00001){
		ret = 3.7469474;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .995) < 0.00001){
		ret = 4.6040949;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .9975) < 0.00001){
		ret = 5.5975684;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .999) < 0.00001){
		ret = 7.1731822;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .9995) < 0.00001){
		ret = 8.6103016;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .99975) < 0.00001){
		ret = 10.306255;
	}
	else if(grados_libertad == 4 && abs(probabilidadIzquierda - .9999) < 0.00001){
		ret = 13.033672;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .9) < 0.00001){
		ret = 1.4758840;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .95) < 0.00001){
		ret = 2.0150484;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .975) < 0.00001){
		ret = 2.5705818;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .99) < 0.00001){
		ret = 3.3649300;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .995) < 0.00001){
		ret = 4.0321430;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .9975) < 0.00001){
		ret = 4.7733406;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .999) < 0.00001){
		ret = 5.8934295;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .9995) < 0.00001){
		ret = 6.8688266;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .99975) < 0.00001){
		ret = 7.9756534;
	}
	else if(grados_libertad == 5 && abs(probabilidadIzquierda - .9999) < 0.00001){
		ret = 9.6775663;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .9) < 0.00001){
		ret = 1.4397557;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .95) < 0.00001){
		ret = 1.9431803;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .975) < 0.00001){
		ret = 2.4469119;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .99) < 0.00001){
		ret = 3.1426684;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .995) < 0.00001){
		ret = 3.7074280;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .9975) < 0.00001){
		ret = 4.3168271;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .999) < 0.00001){
		ret = 5.2076262;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .9995) < 0.00001){
		ret = 5.9588162;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .99975) < 0.00001){
		ret = 6.7883400;
	}
	else if(grados_libertad == 6 && abs(probabilidadIzquierda - .9999) < 0.00001){
		ret = 8.0247928;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .9) < 0.00001){
		ret = 1.4149239;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .95) < 0.00001){
		ret = 1.8945786;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .975) < 0.00001){
		ret = 2.3646243;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .99) < 0.00001){
		ret = 2.9979516;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .995) < 0.00001){
		ret = 3.4994833;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .9975) < 0.00001){
		ret = 4.0293372;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .999) < 0.00001){
		ret = 4.7852896;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .9995) < 0.00001){
		ret = 5.4078825;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .99975) < 0.00001){
		ret = 6.0817562;
	}
	else if(grados_libertad == 7 && abs(probabilidadIzquierda - .9999) < 0.00001){
		ret = 7.0634328;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .9) < 0.00001){
		ret = 1.3968153;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .95) < 0.00001){
		ret = 1.8595480;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .975) < 0.00001){
		ret = 2.3060041;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .99) < 0.00001){
		ret = 2.8964594;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .995) < 0.00001){
		ret = 3.3553873;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .9975) < 0.00001){
		ret = 3.8325187;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .999) < 0.00001){
		ret = 4.5007909;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .9995) < 0.00001){
		ret = 5.0413054;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .99975) < 0.00001){
		ret = 5.6174108;
	}
	else if(grados_libertad == 8 && abs(probabilidadIzquierda - .9999) < 0.00001){
		ret = 6.4419998;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .9) < 0.00001){
		ret = 1.3830287;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .95) < 0.00001){
		ret = 1.8331129;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .975) < 0.00001){
		ret = 2.2621572;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .99) < 0.00001){
		ret = 2.8214379;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .995) < 0.00001){
		ret = 3.2498355;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .9975) < 0.00001){
		ret = 3.6896624;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .999) < 0.00001){
		ret = 4.2968057;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .9995) < 0.00001){
		ret = 4.7809126;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .99975) < 0.00001){
		ret = 5.2906538;
	}
	else if(grados_libertad == 9 && abs(probabilidadIzquierda - .9999) < 0.00001){
		ret = 6.0101321;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3721836;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.8124611;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.2281389;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.7637695;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 3.1692727;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.5814062;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 4.1437005;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 4.5868939;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 5.0489727;
	}
	else if(grados_libertad == 10 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 5.6938201;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3634303;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7958848;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.2009852;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.7180792;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 3.1058065;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.4966142;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 4.0247010;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 4.4369793;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.8633331;
	}
	else if(grados_libertad == 11 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 5.4527621;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3562173;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7822876;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.1788128;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.6809980;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 3.0545396;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.4284442;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.9296333;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 4.3177913;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.7164587;
	}
	else if(grados_libertad == 12 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 5.2632730;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3501713;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7709334;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.1603687;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.6503088;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 3.0122758;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.3724679;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.8519824;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 4.2208317;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.5974615;
	}
	else if(grados_libertad == 13 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 5.1105789;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3450304;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7613101;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.1447867;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.6244941;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.9768427;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.3256958;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.7873902;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 4.1404541;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.4991551;
	}
	else if(grados_libertad == 14 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.9850132;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3406056;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7530504;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.1314495;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.6024803;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.9467129;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.2860386;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.7328344;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 4.0727652;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.4166128;
	}
	else if(grados_libertad == 15 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.8799983;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3367572;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7458837;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.1199053;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.5834872;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.9207816;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.2519929;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.6861548;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 4.0149963;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.3463486;
	}
	else if(grados_libertad == 16 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.7909101;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3333794;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7396067;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.1098156;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.5669340;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.8982305;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.2224499;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.6457674;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.9651263;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.2858283;
	}
	else if(grados_libertad == 17 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.7144065;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3303909;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7340636;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.1009220;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.5523796;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.8784405;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.1965742;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.6104849;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.9216458;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.2331673;
	}
	else if(grados_libertad == 18 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.6480142;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3277282;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7291328;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0930241;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.5394832;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.8609346;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.1737245;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.5794001;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.8834059;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.1869353;
	}
	else if(grados_libertad == 19 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.5898646;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3253407;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7247182;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0859634;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.5279770;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.8453397;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.1534005;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.5518083;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.8495163;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.1460278;
	}
	else if(grados_libertad == 20 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.5385209;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3231879;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7207429;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0796138;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.5176480;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.8313596;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.1352062;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.5271537;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.8192772;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.1095789;
	}
	else if(grados_libertad == 21 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.4928601;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3212367;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7171444;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0738731;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.5083246;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.8187561;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.1188242;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.5049920;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.7921307;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.0769001;
	}
	else if(grados_libertad == 22 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.4519927;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3194602;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7138715;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0686576;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4998667;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.8073357;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.1039970;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.4849644;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.7676268;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.0474371;
	}
	else if(grados_libertad == 23 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.4152047;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3178359;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7108821;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0638986;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4921595;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7969395;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0905135;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.4667773;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.7453986;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 4.0207390;
	}
	else if(grados_libertad == 24 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.3819168;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3163451;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7081408;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0595386;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4851072;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7874358;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0781995;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.4501887;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.7251439;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.9964353;
	}
	else if(grados_libertad == 25 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.3516539;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3149719;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7056179;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0555294;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4786298;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7787145;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0669091;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.4349972;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.7066117;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.9742185;
	}
	else if(grados_libertad == 26 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.3240230;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3137029;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7032884;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0518305;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4726599;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7706830;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0565201;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.4210336;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.6895917;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.9538317;
	}
	else if(grados_libertad == 27 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.2986963;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3125268;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.7011309;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0484071;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4671401;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7632625;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0469288;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.4081552;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.6739064;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.9350581;
	}
	else if(grados_libertad == 28 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.2753979;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3114336;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6991270;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0452296;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4620214;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7563859;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0380467;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3962403;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.6594050;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.9177141;
	}
	else if(grados_libertad == 29 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.2538941;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3104150;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6972609;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0422725;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4572615;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7499957;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0297982;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3851849;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.6459586;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.9016427;
	}
	else if(grados_libertad == 30 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.2339860;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3094635;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6955188;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0395134;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4528242;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7440419;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0221178;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3748993;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.6334563;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.8867090;
	}
	else if(grados_libertad == 31 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.2155026;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3085728;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6938887;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0369333;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4486776;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7384815;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0149489;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3653059;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.6218023;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.8727966;
	}
	else if(grados_libertad == 32 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.1982967;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3077371;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6923603;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0345153;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4447942;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7332766;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0082420;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3563373;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.6109130;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.8598044;
	}
	else if(grados_libertad == 33 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.1822405;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3069516;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6909243;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0322445;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4411496;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7283944;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 3.0019539;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3479343;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.6007158;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.8476442;
	}
	else if(grados_libertad == 34 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.1672229;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3062118;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6895725;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0301079;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4377225;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7238056;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9960466;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3400452;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5911468;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.8362386;
	}
	else if(grados_libertad == 35 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.1531463;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3055139;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6882977;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0280940;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4344941;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7194846;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9904866;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3326243;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5821497;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.8255196;
	}
	else if(grados_libertad == 36 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.1399252;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3048544;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6870936;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0261925;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4314474;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7154087;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9852441;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3256310;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5736748;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.8154272;
	}
	else if(grados_libertad == 37 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.1274840;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3042302;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6859545;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0243942;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4285676;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7115576;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9802926;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3190297;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5656781;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.8059080;
	}
	else if(grados_libertad == 38 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.1157559;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3036386;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6848751;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0226909;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4258414;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7079132;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9756088;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3127881;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5581201;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7969146;
	}
	else if(grados_libertad == 39 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.1046813;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3030771;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6838510;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0210754;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4232568;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7044593;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9711713;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3068777;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5509658;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7884046;
	}
	else if(grados_libertad == 40 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0942071;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3025434;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6828780;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0195410;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4208030;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.7011813;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9669613;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.3012729;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5441836;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7803402;
	}
	else if(grados_libertad == 41 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0842859;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3020355;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6819524;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0180817;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4184704;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6980662;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9629618;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2959505;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5377454;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7726873;
	}
	else if(grados_libertad == 42 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0748752;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3015516;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6810707;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0166922;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4162501;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6951021;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9591573;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2908898;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5316257;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7654152;
	}
	else if(grados_libertad == 43 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0659364;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3010901;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6802300;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0153676;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4141344;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6922783;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9555340;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2860719;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5258013;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7584962;
	}
	else if(grados_libertad == 44 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0574352;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3006493;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6794274;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0141034;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4121159;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6895850;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9520791;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2814798;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5202515;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7519052;
	}
	else if(grados_libertad == 45 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0493400;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.3002280;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6786604;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0128956;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4101881;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6870135;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9487813;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2770980;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5149572;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7456195;
	}
	else if(grados_libertad == 46 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0416226;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2998249;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6779267;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0117405;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4083451;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6845556;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9456301;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2729124;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5099013;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7396183;
	}
	else if(grados_libertad == 47 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0342572;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2994389;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6772242;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0106348;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4065813;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6822040;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9426158;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2689100;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5050680;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7338828;
	}
	else if(grados_libertad == 48 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0272201;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2990688;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6765509;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0095752;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4048918;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6799520;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9397298;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2650792;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.5004429;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7283958;
	}
	else if(grados_libertad == 49 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0204901;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2987137;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6759050;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0085591;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4032719;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6777933;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9369641;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2614091;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4960129;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7231413;
	}
	else if(grados_libertad == 50 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0140473;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2983727;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6752850;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0075838;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4017175;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6757222;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9343112;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2578898;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4917659;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7181051;
	}
	else if(grados_libertad == 51 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0078739;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2980450;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6746892;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0066468;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.4002247;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6737336;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9317645;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2545122;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4876907;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7132737;
	}
	else if(grados_libertad == 52 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 4.0019533;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2977298;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6741162;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0057460;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3987898;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6718226;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9293177;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2512680;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4837773;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7086349;
	}
	else if(grados_libertad == 53 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9962703;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2974265;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6735649;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0048793;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3974096;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6699848;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9269650;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2481493;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4800161;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.7041775;
	}
	else if(grados_libertad == 54 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9908109;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2971343;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6730340;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0040448;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3960811;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6682160;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9247010;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2451491;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4763984;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6998909;
	}
	else if(grados_libertad == 55 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9855621;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2968527;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6725223;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0032407;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3948012;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6665124;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9225210;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2422607;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4729161;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6957657;
	}
	else if(grados_libertad == 56 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9805121;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2965810;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6720289;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0024655;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3935675;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6648705;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9204202;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2394780;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4695619;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6917928;
	}
	else if(grados_libertad == 57 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9756497;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2963189;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6715528;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0017175;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3923775;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6632870;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9183945;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2367953;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4663288;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6879639;
	}
	else if(grados_libertad == 58 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9709647;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2960657;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6710930;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0009954;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3912288;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6617588;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9164398;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2342073;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4632103;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6842715;
	}
	else if(grados_libertad == 59 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9664475;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2958211;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6706489;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 2.0002978;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3901195;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6602830;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9145526;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2317091;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4602005;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6807082;
	}
	else if(grados_libertad == 60 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9620894;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2955846;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6702195;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9996236;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3890474;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6588571;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9127293;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2292961;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4572937;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6772675;
	}
	else if(grados_libertad == 61 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9578820;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2953558;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6698042;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9989715;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3880108;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6574786;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9109669;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2269640;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4544848;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6739432;
	}
	else if(grados_libertad == 62 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9538176;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2951343;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6694022;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9983405;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3870079;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6561450;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9092622;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2247087;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4517689;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6707294;
	}
	else if(grados_libertad == 63 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9498892;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2949198;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6690130;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9977297;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3860370;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6548543;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9076126;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2225267;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4491415;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6676207;
	}
	else if(grados_libertad == 64 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9460900;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2947120;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6686360;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9971379;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3850968;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6536045;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9060153;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2204143;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4465984;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6646121;
	}
	else if(grados_libertad == 65 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9424137;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2945106;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6682705;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9965644;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3841857;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6523935;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9044679;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2183682;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4441354;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6616988;
	}
	else if(grados_libertad == 66 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9388545;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2943152;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6679161;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9960084;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3833025;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6512197;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9029682;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2163855;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4417489;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6588763;
	}
	else if(grados_libertad == 67 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9354069;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2941256;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6675723;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9954689;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3824458;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6500813;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9015140;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2144632;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4394355;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6561404;
	}
	else if(grados_libertad == 68 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9320656;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2939416;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6672385;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9949454;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3816145;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6489768;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.9001031;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2125986;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4371917;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6534874;
	}
	else if(grados_libertad == 69 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9288259;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2937629;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6669145;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9944371;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3808075;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6479046;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8987338;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2107891;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4350145;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6509133;
	}
	else if(grados_libertad == 70 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9256832;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2935893;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6665997;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9939434;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3800237;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6468634;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8974041;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2090323;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4329010;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6484148;
	}
	else if(grados_libertad == 71 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9226333;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2934205;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6662937;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9934636;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3792621;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6458519;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8961125;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2073260;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4308484;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6459886;
	}
	else if(grados_libertad == 72 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9196719;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2932564;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6659962;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9929971;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3785219;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6448688;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8948573;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2056679;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4288542;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6436316;
	}
	else if(grados_libertad == 73 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9167955;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2930968;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6657069;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9925435;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3778020;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6439129;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8936369;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2040562;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4269158;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6413408;
	}
	else if(grados_libertad == 74 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9140003;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2929415;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6654254;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9921022;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3771018;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6429831;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8924500;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2024888;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4250309;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6391136;
	}
	else if(grados_libertad == 75 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9112830;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2927903;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6651514;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9916726;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3764204;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6420783;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8912952;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.2009641;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4231975;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6369473;
	}
	else if(grados_libertad == 76 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9086403;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2926430;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6648845;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9912544;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3757570;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6411976;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8901711;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1994801;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4214133;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6348394;
	}
	else if(grados_libertad == 77 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9060693;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2924996;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6646246;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9908471;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3751110;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6403400;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8890767;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1980354;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4196765;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6327877;
	}
	else if(grados_libertad == 78 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9035670;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2923598;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6643714;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9904502;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3744816;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6395046;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8880107;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1966284;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4179851;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6307898;
	}
	else if(grados_libertad == 79 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.9011307;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2922236;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6641246;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9900634;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3738683;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6386906;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8869721;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1952577;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4163375;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6288438;
	}
	else if(grados_libertad == 80 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8987580;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2920907;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6638839;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9896863;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3732704;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6378971;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8859597;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1939218;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4147319;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6269476;
	}
	else if(grados_libertad == 81 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8964462;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2919611;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6636492;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9893186;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3726873;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6371234;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8849727;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1926195;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4131667;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6250993;
	}
	else if(grados_libertad == 82 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8941931;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2918347;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6634202;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9889598;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3721186;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6363688;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8840100;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1913494;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4116405;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6232971;
	}
	else if(grados_libertad == 83 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8919965;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2917113;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6631967;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9886097;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3715637;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6356325;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8830708;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1901105;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4101518;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6215394;
	}
	else if(grados_libertad == 84 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8898543;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2915908;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6629785;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9882679;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3710220;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6349139;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8821543;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1889016;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4086993;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6198245;
	}
	else if(grados_libertad == 85 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8877644;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2914732;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6627654;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9879342;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3704932;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6342123;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8812596;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1877216;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4072816;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6181509;
	}
	else if(grados_libertad == 86 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8857251;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2913582;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6625573;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9876083;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3699768;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6335272;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8803859;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1865694;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4058975;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6165170;
	}
	else if(grados_libertad == 87 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8837344;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2912459;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6623540;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9872899;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3694723;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6328580;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8795326;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1854442;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4045458;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6149216;
	}
	else if(grados_libertad == 88 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8817908;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2911362;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6621553;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9869787;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3689793;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6322042;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8786989;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1843450;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4032255;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6133632;
	}
	else if(grados_libertad == 89 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8798924;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2910289;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6619611;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9866745;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3684975;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6315652;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8778842;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1832708;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4019353;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6118405;
	}
	else if(grados_libertad == 90 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8780378;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2909240;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6617712;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9863772;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3680264;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6309405;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8770878;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1822209;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.4006744;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6103525;
	}
	else if(grados_libertad == 91 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8762254;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2908214;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6615854;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9860863;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3675658;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6303296;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8763090;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1811944;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.3994416;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6088978;
	}
	else if(grados_libertad == 92 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8744539;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2907210;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6614037;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9858018;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3671152;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6297321;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8755474;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1801906;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.3982362;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6074754;
	}
	else if(grados_libertad == 93 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8727218;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2906227;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6612259;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9855234;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3666744;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6291476;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8748024;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1792086;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.3970571;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6060843;
	}
	else if(grados_libertad == 94 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8710279;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2905265;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6610518;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9852510;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3662430;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6285757;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8740734;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1782479;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.3959036;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6047233;
	}
	else if(grados_libertad == 95 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8693710;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2904324;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6608814;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9849843;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3658207;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6280158;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8733599;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1773077;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.3947747;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6033916;
	}
	else if(grados_libertad == 96 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8677497;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2903402;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6607146;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9847232;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3654073;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6274678;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8726614;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1763874;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.3936698;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6020882;
	}
	else if(grados_libertad == 97 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8661630;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2902499;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6605512;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9844675;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3650024;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6269311;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8719775;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1754863;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.3925881;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.6008122;
	}
	else if(grados_libertad == 98 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8646099;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2901614;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6603912;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9842170;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3646059;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6264055;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8713077;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1746038;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.3915288;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.5995627;
	}
	else if(grados_libertad == 99 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8630891;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.9) < 0.00001){
		ret = 1.2900748;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.95) < 0.00001){
		ret = 1.6602343;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.975) < 0.00001){
		ret = 1.9839715;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.99) < 0.00001){
		ret = 2.3642174;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.995) < 0.00001){
		ret = 2.6258905;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.9975) < 0.00001){
		ret = 2.8706515;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.999) < 0.00001){
		ret = 3.1737395;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.9995) < 0.00001){
		ret = 3.3904913;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.99975) < 0.00001){
		ret = 3.5983390;
	}
	else if(grados_libertad == 100 && abs(probabilidadIzquierda -.9999) < 0.00001){
		ret = 3.8615998;
	}
	
	if(ret == -1){
		//char error_msg[150];
		//sprintf(error_msg, "No tStudent value for %i grados de libertad y prob. a la izquierda %f", grados_libertad, probabilidadIzquierda);
		string error_msg = string("No tStudent value for ") + to_string(grados_libertad) + string(" grados de libertad y prob. a la izquierda ") + to_string(probabilidadIzquierda);
		throw error_msg;
	}
    
    return ret;
    
}

#endif
