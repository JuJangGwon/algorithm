#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[301];

int main()
{
    int a = 1;

    dp[290] = 42;
    dp[58] = 468;
    dp[47] = 335;
    dp[119] = 1;
    dp[279] = 170;
    dp[229] = 225;
    dp[271] = 479;
    dp[201] = 359;
    dp[66] = 463;
    dp[142] = 465;
    dp[269] = 205;
    dp[254] = 146;
    dp[144] = 282;
    dp[173] = 328;
    dp[116] = 462;
    dp[267] = 492;
    dp[299] = 496;
    dp[236] = 443;
    dp[183] = 328;
    dp[297] = 437;
    dp[11] = 392;
    dp[164] = 105;
    dp[256] = 403;
    dp[132] = 154;
    dp[46] = 293;
    dp[189] = 383;
    dp[112] = 422;
    dp[237] = 217;
    dp[33] = 219;
    dp[80] = 396;
    dp[208] = 448;
    dp[260] = 227;
    dp[154] = 272;
    dp[71] = 39;
    dp[151] = 370;
    dp[97] = 413;
    dp[91] = 168;
    dp[191] = 300;
    dp[103] = 36;
    dp[69] = 395;
    dp[62] = 204;
    dp[6] = 312;
    dp[248] = 323;
    dp[74] = 334;
    dp[22] = 174;
    dp[155] = 165;
    dp[8] = 142;
    dp[219] = 212;
    dp[111] = 254;
    dp[265] = 369;
    dp[153] = 48;
    dp[7] = 145;
    dp[165] = 163;
    dp[12] = 258;
    dp[14] = 38;
    dp[233] = 360;
    dp[157] = 224;
    dp[118] = 242;
    dp[128] = 30;
    dp[42] = 279;
    dp[99] = 317;
    dp[174] = 36;
    dp[235] = 191;
    dp[205] = 343;
    dp[131] = 289;
    dp[230] = 107;
    dp[255] = 41;
    dp[25] = 443;
    dp[61] = 265;
    dp[138] = 149;
    dp[295] = 447;
    dp[283] = 306;
    dp[286] = 391;
    dp[83] = 230;
    dp[34] = 371;
    dp[228] = 351;
    dp[60] = 7;
    dp[296] = 102;
    dp[218] = 394;
    dp[72] = 49;
    dp[146] = 130;
    dp[101] = 125;
    dp[232] = 85;
    dp[259] = 455;
    dp[188] = 257;
    dp[123] = 341;
    dp[96] = 467;
    dp[100] = 377;
    dp[110] = 432;
    dp[272] = 309;
    dp[130] = 445;
    dp[102] = 440;
    dp[287] = 127;
    dp[117] = 324;
    dp[243] = 38;
    dp[70] = 39;
    dp[273] = 119;
    dp[253] = 83;
    dp[244] = 430;
    dp[93] = 42;
    dp[32] = 334;
    dp[285] = 116;
    dp[158] = 140;
    dp[266] = 159;
    dp[171] = 205;
    dp[175] = 431;
    dp[262] = 478;
    dp[250] = 307;
    dp[9] = 174;
    dp[2] = 387;
    dp[216] = 22;
    dp[76] = 246;
    dp[73] = 425;
    dp[134] = 73;
    dp[196] = 271;
    dp[38] = 330;
    dp[5] = 278;
    dp[284] = 74;
    dp[300] = 98;
    dp[221] = 13;
    dp[26] = 487;
    dp[185] = 291;
    dp[86] = 162;
    dp[89] = 137;
    dp[54] = 356;
    dp[199] = 268;
    dp[78] = 156;
    dp[109] = 75;
    dp[245] = 32;
    dp[4] = 53;
    dp[206] = 351;
    dp[210] = 151;
    dp[129] = 442;
    dp[270] = 225;
    dp[241] = 467;
    dp[166] = 431;
    dp[44] = 108;
    dp[139] = 192;
    dp[160] = 8;
    dp[124] = 338;
    dp[43] = 458;
    dp[49] = 288;
    dp[41] = 254;
    dp[77] = 384;
    dp[136] = 446;
    dp[53] = 410;
    dp[35] = 210;
    dp[257] = 259;
    dp[55] = 222;
    dp[10] = 89;
    dp[18] = 423;
    dp[159] = 447;
    dp[161] = 7;
    dp[212] = 31;
    dp[217] = 414;
    dp[293] = 169;
    dp[48] = 401;
    dp[15] = 92;
    dp[81] = 263;
    dp[45] = 156;
    dp[152] = 411;
    dp[104] = 360;
    dp[127] = 125;
    dp[213] = 38;
    dp[162] = 49;
    dp[121] = 484;
    dp[198] = 96;
    dp[64] = 42;
    dp[23] = 103;
    dp[195] = 351;
    dp[140] = 292;
    dp[147] = 337;
    dp[193] = 375;
    dp[214] = 21;
    dp[90] = 97;
    dp[222] = 22;
    dp[63] = 349;
    dp[177] = 200;
    dp[192] = 169;
    dp[203] = 485;
    dp[122] = 282;
    dp[288] = 235;
    dp[39] = 54;
    dp[56] = 500;
    dp[36] = 419;
    dp[24] = 439;
    dp[264] = 401;
    dp[226] = 289;
    dp[240] = 128;
    dp[30] = 468;
    dp[125] = 229;
    dp[31] = 394;
    dp[182] = 149;
    dp[291] = 484;
    dp[261] = 308;
    dp[239] = 422;
    dp[52] = 311;
    dp[194] = 118;
    dp[135] = 314;
    dp[13] = 15;
    dp[163] = 310;
    dp[68] = 117;
    dp[225] = 436;
    dp[85] = 452;
    dp[276] = 101;
    dp[106] = 250;
    dp[204] = 20;
    dp[67] = 57;
    dp[282] = 299;
    dp[19] = 304;
    dp[16] = 225;
    dp[75] = 9;
    dp[150] = 345;
    dp[234] = 110;
    dp[79] = 490;
    dp[59] = 203;
    dp[167] = 196;
    dp[172] = 486;
    dp[141] = 94;
    dp[209] = 344;
    dp[249] = 24;
    dp[57] = 88;
    dp[105] = 315;
    dp[231] = 4;
    dp[98] = 449;
    dp[289] = 201;
    dp[1] = 459;
    dp[184] = 119;
    dp[133] = 81;
    dp[215] = 297;
    dp[120] = 299;
    dp[51] = 282;
    dp[252] = 90;
    dp[292] = 299;
    dp[211] = 10;
    dp[220] = 158;
    dp[3] = 473;
    dp[65] = 12;
    dp[258] = 39;
    dp[280] = 293;
    dp[281] = 39;
    dp[242] = 180;
    dp[29] = 191;
    dp[263] = 158;
    dp[88] = 459;
    dp[107] = 192;
    dp[298] = 316;
    dp[94] = 389;
    dp[50] = 157;
    dp[246] = 12;
    dp[278] = 203;
    dp[114] = 135;
    dp[223] = 273;
    dp[168] = 56;
    dp[200] = 329;
    dp[92] = 147;
    dp[277] = 363;
    dp[84] = 387;
    dp[275] = 376;
    dp[251] = 434;
    dp[268] = 370;
    dp[143] = 143;
    dp[207] = 345;
    dp[21] = 417;
    dp[145] = 382;
    dp[149] = 499;
    dp[82] = 323;
    dp[170] = 152;
    dp[224] = 22;
    dp[187] = 200;
    dp[179] = 58;
    dp[181] = 477;
    dp[40] = 393;
    dp[37] = 390;
    dp[227] = 76;
    dp[95] = 213;
    dp[190] = 101;
    dp[294] = 11;
    dp[197] = 4;
    dp[156] = 370;
    dp[87] = 362;
    dp[113] = 189;
    dp[238] = 402;
    dp[190] = 290;
    dp[274] = 256;
    dp[108] = 424;
    dp[126] = 3;
    dp[178] = 86;
    dp[20] = 183;
    dp[186] = 286;
    dp[137] = 89;
    dp[202] = 427;
    dp[247] = 118;
    dp[17] = 258;
    dp[28] = 333;
    dp[169] = 433;
    dp[148] = 170;
    dp[115] = 155;
    dp[27] = 222;
    dp[176] = 190;

    int sum = 0;

    vector<pair<int, int> > p;

    for (int i = 1; i < 300; i++)
    {
        p.push_back(make_pair(dp[i], i));
    }
    sort(p.begin(), p.end());
    int status = p[0].first;

    for (int i = 1; i < 300; i++)
    {
        status += p[i].first;
        sum += status + p[i].second;
    }
    cout << sum;
}