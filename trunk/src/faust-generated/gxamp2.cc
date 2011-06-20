namespace gxamp2 {
// generated from file '../src/faust/gxamp2.dsp'

double 	fConst0;
double 	fConst1;
double 	fConst2;
double 	fConst3;
double 	fConst4;
FAUSTFLOAT&	fslider0 = get_alias("amp2.stage2.gain1");
double 	fRec3[2];
double 	fConst5;
double 	fConst6;
double 	fConst7;
FAUSTFLOAT&	fslider1 = get_alias("gxdistortion.wet_dry");
FAUSTFLOAT&	fslider2 = get_alias("gxdistortion.drive");
double 	fConst8;
double 	fConst9;
double 	fConst10;
double 	fConst11;
double 	fConst12;
double 	fConst13;
double 	fConst14;
double 	fConst15;
double 	fConst16;
double 	fConst17;
double 	fConst18;
double 	fConst19;
double 	fConst20;
double 	fConst21;
double 	fConst22;
double 	fConst23;
double 	fConst24;
double 	fConst25;
double 	fConst26;
double 	fConst27;
double 	fConst28;
double 	fConst29;
double 	fConst30;
double 	fConst31;
double 	fConst32;
double 	fConst33;
double 	fConst34;
double 	fRec16[3];
double 	fVec0[2];
double 	fConst35;
double 	fConst36;
double 	fRec15[2];
double 	fConst37;
double 	fConst38;
double 	fRec14[2];
double 	fRec13[3];
double 	fConst39;
double 	fRec12[3];
double 	fRec11[3];
double 	fConst40;
double 	fConst41;
double 	fConst42;
double 	fConst43;
double 	fConst44;
double 	fConst45;
double 	fConst46;
double 	fConst47;
double 	fConst48;
double 	fRec22[2];
double 	fRec21[3];
double 	fVec1[2];
double 	fConst49;
double 	fRec20[2];
double 	fRec19[3];
double 	fVec2[2];
double 	fConst50;
double 	fConst51;
double 	fRec18[2];
double 	fRec17[3];
double 	fConst52;
double 	fRec24[2];
double 	fRec23[3];
double 	fConst53;
double 	fRec27[2];
double 	fRec26[3];
double 	fConst54;
double 	fRec25[3];
double 	fVec3[2];
double 	fConst55;
double 	fRec10[2];
FAUSTFLOAT&	fslider3 = get_alias("amp2.stage1.Pregain");
double 	fRec28[2];
double 	fConst56;
double 	fConst57;
double 	fConst58;
double 	fVec4[2];
double 	fConst59;
double 	fRec29[2];
double 	fRec9[2];
double 	fConst60;
double 	fRec8[2];
double 	fConst61;
double 	fRec7[2];
double 	fConst62;
double 	fConst63;
double 	fConst64;
double 	fVec5[2];
double 	fConst65;
double 	fRec30[2];
double 	fRec6[2];
double 	fRec5[2];
double 	fRec4[2];
double 	fRec2[3];
double 	fConst66;
double 	fConst67;
double 	fConst68;
double 	fVec6[2];
double 	fConst69;
double 	fRec31[2];
double 	fRec1[2];
double 	fRec0[2];
int	fSamplingFreq;

void init(int samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = (1.0 / tan((97.38937226128358 / fSamplingFreq)));
	fConst1 = (1 + fConst0);
	fConst2 = (0 - ((1 - fConst0) / fConst1));
	fConst3 = log((7539.822368615503 / fSamplingFreq));
	fConst4 = (0 - (1.8442 * cos(exp((0.07238887 + (fConst3 * (1.31282248 + (fConst3 * (0.43359433 + (fConst3 * (0.27547621 + (fConst3 * (0.06446806 + (0.00506158 * fConst3))))))))))))));
	for (int i=0; i<2; i++) fRec3[i] = 0;
	fConst5 = (1.0 / tan((20517.741620594938 / fSamplingFreq)));
	fConst6 = (1 + fConst5);
	fConst7 = (0 - ((1 - fConst5) / fConst6));
	fConst8 = tan((942.4777960769379 / fSamplingFreq));
	fConst9 = (1.0 / faustpower<2>(fConst8));
	fConst10 = (2 * (1 - fConst9));
	fConst11 = (1.0 / fConst8);
	fConst12 = (1 + ((fConst11 - 1.0) / fConst8));
	fConst13 = (1.0 / (1 + ((1.0 + fConst11) / fConst8)));
	fConst14 = tan((3769.9111843077517 / fSamplingFreq));
	fConst15 = (1.0 / faustpower<2>(fConst14));
	fConst16 = (2 * (1 - fConst15));
	fConst17 = (1.0 / fConst14);
	fConst18 = (1 + ((fConst17 - 1.0) / fConst14));
	fConst19 = (1.0 / (1 + ((1.0 + fConst17) / fConst14)));
	fConst20 = tan((10053.096491487338 / fSamplingFreq));
	fConst21 = (1.0 / faustpower<2>(fConst20));
	fConst22 = (2 * (1 - fConst21));
	fConst23 = (1.0 / fConst20);
	fConst24 = (1 + ((fConst23 - 1.0000000000000004) / fConst20));
	fConst25 = (1 + ((1.0000000000000004 + fConst23) / fConst20));
	fConst26 = (1.0 / fConst25);
	fConst27 = (1 + fConst23);
	fConst28 = (0 - ((1 - fConst23) / fConst27));
	fConst29 = tan((47123.8898038469 / fSamplingFreq));
	fConst30 = (2 * (1 - (1.0 / faustpower<2>(fConst29))));
	fConst31 = (1.0 / fConst29);
	fConst32 = (1 + ((fConst31 - 1.414213562373095) / fConst29));
	fConst33 = (1 + ((1.414213562373095 + fConst31) / fConst29));
	fConst34 = (1.0 / fConst33);
	for (int i=0; i<3; i++) fRec16[i] = 0;
	for (int i=0; i<2; i++) fVec0[i] = 0;
	fConst35 = (0 - fConst0);
	fConst36 = (1.0 / (fConst1 * fConst33));
	for (int i=0; i<2; i++) fRec15[i] = 0;
	fConst37 = (0 - fConst23);
	fConst38 = (1.0 / fConst27);
	for (int i=0; i<2; i++) fRec14[i] = 0;
	for (int i=0; i<3; i++) fRec13[i] = 0;
	fConst39 = (2 * (0 - fConst21));
	for (int i=0; i<3; i++) fRec12[i] = 0;
	for (int i=0; i<3; i++) fRec11[i] = 0;
	fConst40 = (1 + ((fConst11 - 1.0000000000000004) / fConst8));
	fConst41 = (1.0 / (1 + ((fConst11 + 1.0000000000000004) / fConst8)));
	fConst42 = (1 + fConst11);
	fConst43 = (0 - ((1 - fConst11) / fConst42));
	fConst44 = (1 + ((fConst17 - 1.0000000000000004) / fConst14));
	fConst45 = (1 + ((fConst17 + 1.0000000000000004) / fConst14));
	fConst46 = (1.0 / fConst45);
	fConst47 = (1 + fConst17);
	fConst48 = (0 - ((1 - fConst17) / fConst47));
	for (int i=0; i<2; i++) fRec22[i] = 0;
	for (int i=0; i<3; i++) fRec21[i] = 0;
	for (int i=0; i<2; i++) fVec1[i] = 0;
	fConst49 = (1.0 / (fConst47 * fConst25));
	for (int i=0; i<2; i++) fRec20[i] = 0;
	for (int i=0; i<3; i++) fRec19[i] = 0;
	for (int i=0; i<2; i++) fVec2[i] = 0;
	fConst50 = (0 - fConst11);
	fConst51 = (1.0 / (fConst42 * fConst45));
	for (int i=0; i<2; i++) fRec18[i] = 0;
	for (int i=0; i<3; i++) fRec17[i] = 0;
	fConst52 = (2 * (0 - fConst9));
	for (int i=0; i<2; i++) fRec24[i] = 0;
	for (int i=0; i<3; i++) fRec23[i] = 0;
	fConst53 = (0 - fConst17);
	for (int i=0; i<2; i++) fRec27[i] = 0;
	for (int i=0; i<3; i++) fRec26[i] = 0;
	fConst54 = (2 * (0 - fConst15));
	for (int i=0; i<3; i++) fRec25[i] = 0;
	for (int i=0; i<2; i++) fVec3[i] = 0;
	fConst55 = (1.5848931924611136 / fConst6);
	for (int i=0; i<2; i++) fRec10[i] = 0;
	for (int i=0; i<2; i++) fRec28[i] = 0;
	fConst56 = (1.0 / tan((270.1769682087222 / fSamplingFreq)));
	fConst57 = (1 + fConst56);
	fConst58 = (0 - ((1 - fConst56) / fConst57));
	for (int i=0; i<2; i++) fVec4[i] = 0;
	fConst59 = (0.027 / fConst57);
	for (int i=0; i<2; i++) fRec29[i] = 0;
	for (int i=0; i<2; i++) fRec9[i] = 0;
	fConst60 = (0.025 / fConst1);
	for (int i=0; i<2; i++) fRec8[i] = 0;
	fConst61 = (0.77 / fConst6);
	for (int i=0; i<2; i++) fRec7[i] = 0;
	fConst62 = (1.0 / tan((414.6902302738527 / fSamplingFreq)));
	fConst63 = (1 + fConst62);
	fConst64 = (0 - ((1 - fConst62) / fConst63));
	for (int i=0; i<2; i++) fVec5[i] = 0;
	fConst65 = (0.015 / fConst63);
	for (int i=0; i<2; i++) fRec30[i] = 0;
	for (int i=0; i<2; i++) fRec6[i] = 0;
	for (int i=0; i<2; i++) fRec5[i] = 0;
	for (int i=0; i<2; i++) fRec4[i] = 0;
	for (int i=0; i<3; i++) fRec2[i] = 0;
	fConst66 = (1.0 / tan((609.4689747964198 / fSamplingFreq)));
	fConst67 = (1 + fConst66);
	fConst68 = (0 - ((1 - fConst66) / fConst67));
	for (int i=0; i<2; i++) fVec6[i] = 0;
	fConst69 = (0.0082 / fConst67);
	for (int i=0; i<2; i++) fRec31[i] = 0;
	for (int i=0; i<2; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRec0[i] = 0;
}

void compute(int count, float *input0, float *output0)
{
	double 	fSlow0 = (0.0010000000000000009 * pow(10,(0.05 * fslider0)));
	double 	fSlow1 = fslider1;
	double 	fSlow2 = (0.01 * fSlow1);
	double 	fSlow3 = (1 - fSlow2);
	double 	fSlow4 = fslider2;
	double 	fSlow5 = (1.25 * fSlow4);
	double 	fSlow6 = (2 * (fSlow4 - 0.5));
	double 	fSlow7 = (0.01 * (fSlow1 * (1 - max(0, fSlow6))));
	double 	fSlow8 = pow(1e+01,(0.8 * fSlow4));
	double 	fSlow9 = (fConst41 * pow(1e+01,(2 * fSlow4)));
	double 	fSlow10 = (fConst41 * pow(1e+01,(0.9 * fSlow4)));
	double 	fSlow11 = pow(1e+01,(1.2 * fSlow4));
	double 	fSlow12 = (1 - max(0, (0 - fSlow6)));
	double 	fSlow13 = (0.0010000000000000009 * pow(10,(0.05 * fslider3)));
	for (int i=0; i<count; i++) {
		fRec3[0] = (fSlow0 + (0.999 * fRec3[1]));
		double fTemp0 = (double)input0[i];
		double fTemp1 = (fConst10 * fRec11[1]);
		double fTemp2 = (fConst16 * fRec12[1]);
		fRec16[0] = ((fSlow2 * fTemp0) - (fConst34 * ((fConst32 * fRec16[2]) + (fConst30 * fRec16[1]))));
		double fTemp3 = (fRec16[2] + (fRec16[0] + (2 * fRec16[1])));
		fVec0[0] = fTemp3;
		fRec15[0] = ((fConst36 * ((fConst35 * fVec0[1]) + (fConst0 * fVec0[0]))) + (fConst2 * fRec15[1]));
		fRec14[0] = ((fConst38 * ((fConst37 * fRec15[1]) + (fConst23 * fRec15[0]))) + (fConst28 * fRec14[1]));
		fRec13[0] = (fRec14[0] - (fConst26 * ((fConst24 * fRec13[2]) + (fConst22 * fRec13[1]))));
		fRec12[0] = ((fConst26 * (((fConst21 * fRec13[0]) + (fConst39 * fRec13[1])) + (fConst21 * fRec13[2]))) - (fConst19 * ((fConst18 * fRec12[2]) + fTemp2)));
		fRec11[0] = ((fRec12[2] + (fConst19 * (fTemp2 + (fConst18 * fRec12[0])))) - (fConst13 * ((fConst12 * fRec11[2]) + fTemp1)));
		double fTemp4 = max(-1, min(1, (fSlow8 * (fRec11[2] + (fConst13 * (fTemp1 + (fConst12 * fRec11[0])))))));
		fRec22[0] = ((fConst38 * (fRec15[0] + fRec15[1])) + (fConst28 * fRec22[1]));
		fRec21[0] = (fRec22[0] - (fConst26 * ((fConst24 * fRec21[2]) + (fConst22 * fRec21[1]))));
		double fTemp5 = (fRec21[2] + (fRec21[0] + (2 * fRec21[1])));
		fVec1[0] = fTemp5;
		fRec20[0] = ((fConst49 * (fVec1[0] + fVec1[1])) + (fConst48 * fRec20[1]));
		fRec19[0] = (fRec20[0] - (fConst46 * ((fConst44 * fRec19[2]) + (fConst16 * fRec19[1]))));
		double fTemp6 = (fRec19[2] + (fRec19[0] + (2 * fRec19[1])));
		fVec2[0] = fTemp6;
		fRec18[0] = ((fConst51 * ((fConst50 * fVec2[1]) + (fConst11 * fVec2[0]))) + (fConst43 * fRec18[1]));
		fRec17[0] = (fRec18[0] - (fConst41 * ((fConst40 * fRec17[2]) + (fConst10 * fRec17[1]))));
		double fTemp7 = max(-1, min(1, (fSlow9 * (((fConst9 * fRec17[0]) + (fConst52 * fRec17[1])) + (fConst9 * fRec17[2])))));
		fRec24[0] = ((fConst51 * (fVec2[0] + fVec2[1])) + (fConst43 * fRec24[1]));
		fRec23[0] = (fRec24[0] - (fConst41 * ((fConst40 * fRec23[2]) + (fConst10 * fRec23[1]))));
		double fTemp8 = max(-1, min(1, (fSlow10 * (fRec23[2] + (fRec23[0] + (2 * fRec23[1]))))));
		double fTemp9 = (fConst10 * fRec25[1]);
		fRec27[0] = ((fConst49 * ((fConst53 * fVec1[1]) + (fConst17 * fVec1[0]))) + (fConst48 * fRec27[1]));
		fRec26[0] = (fRec27[0] - (fConst46 * ((fConst44 * fRec26[2]) + (fConst16 * fRec26[1]))));
		fRec25[0] = ((fConst46 * (((fConst15 * fRec26[0]) + (fConst54 * fRec26[1])) + (fConst15 * fRec26[2]))) - (fConst13 * ((fConst12 * fRec25[2]) + fTemp9)));
		double fTemp10 = max(-1, min(1, (fSlow11 * (fRec25[2] + (fConst13 * (fTemp9 + (fConst12 * fRec25[0])))))));
		double fTemp11 = (((fTemp10 * (1 - (0.3333333333333333 * faustpower<2>(fTemp10)))) + ((fTemp8 * (1 - (0.3333333333333333 * faustpower<2>(fTemp8)))) + (0.841395141645195 * (fTemp7 * (1 - (0.3333333333333333 * faustpower<2>(fTemp7))))))) + (0.7943282347242815 * (fTemp4 * (1 - (0.3333333333333333 * faustpower<2>(fTemp4))))));
		fVec3[0] = fTemp11;
		fRec10[0] = ((fConst55 * (fVec3[0] + fVec3[1])) + (fConst7 * fRec10[1]));
		fRec28[0] = (fSlow13 + (0.999 * fRec28[1]));
		double fTemp12 = (fRec9[1] - 2.5e+02);
		fVec4[0] = fTemp12;
		fRec29[0] = ((fConst59 * (fVec4[0] + fVec4[1])) + (fConst58 * fRec29[1]));
		fRec9[0] = Ftube2(0, (fRec29[0] + (fRec28[0] * ((fSlow12 * fRec10[0]) + (fTemp0 * (fSlow7 + (fSlow3 * (1 + (fSlow5 * ((4 - (4 * fabs((fSlow3 * fTemp0)))) - 1))))))))));
		fRec8[0] = ((fConst60 * ((fConst35 * fRec9[1]) + (fConst0 * fRec9[0]))) + (fConst2 * fRec8[1]));
		fRec7[0] = ((fConst61 * (fRec8[0] + fRec8[1])) + (fConst7 * fRec7[1]));
		double fTemp13 = (fRec6[1] - 2.5e+02);
		fVec5[0] = fTemp13;
		fRec30[0] = ((fConst65 * (fVec5[0] + fVec5[1])) + (fConst64 * fRec30[1]));
		fRec6[0] = Ftube2(1, (fRec30[0] + (fRec28[0] * fRec7[0])));
		fRec5[0] = ((fConst60 * ((fConst35 * fRec6[1]) + (fConst0 * fRec6[0]))) + (fConst2 * fRec5[1]));
		fRec4[0] = ((fConst61 * (fRec5[0] + fRec5[1])) + (fConst7 * fRec4[1]));
		fRec2[0] = ((fRec4[0] * fRec3[0]) - ((0.8502684100000001 * fRec2[2]) + (fConst4 * fRec2[1])));
		double fTemp14 = (fRec1[1] - 2.5e+02);
		fVec6[0] = fTemp14;
		fRec31[0] = ((fConst69 * (fVec6[0] + fVec6[1])) + (fConst68 * fRec31[1]));
		fRec1[0] = Ftube2(1, ((fRec31[0] + fRec2[0]) - (1.059 * fRec2[1])));
		fRec0[0] = ((fConst60 * ((fConst35 * fRec1[1]) + (fConst0 * fRec1[0]))) + (fConst2 * fRec0[1]));
		output0[i] = (FAUSTFLOAT)(0.77 * fRec0[0]);
		// post processing
		fRec0[1] = fRec0[0];
		fRec1[1] = fRec1[0];
		fRec31[1] = fRec31[0];
		fVec6[1] = fVec6[0];
		fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
		fRec4[1] = fRec4[0];
		fRec5[1] = fRec5[0];
		fRec6[1] = fRec6[0];
		fRec30[1] = fRec30[0];
		fVec5[1] = fVec5[0];
		fRec7[1] = fRec7[0];
		fRec8[1] = fRec8[0];
		fRec9[1] = fRec9[0];
		fRec29[1] = fRec29[0];
		fVec4[1] = fVec4[0];
		fRec28[1] = fRec28[0];
		fRec10[1] = fRec10[0];
		fVec3[1] = fVec3[0];
		fRec25[2] = fRec25[1]; fRec25[1] = fRec25[0];
		fRec26[2] = fRec26[1]; fRec26[1] = fRec26[0];
		fRec27[1] = fRec27[0];
		fRec23[2] = fRec23[1]; fRec23[1] = fRec23[0];
		fRec24[1] = fRec24[0];
		fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
		fRec18[1] = fRec18[0];
		fVec2[1] = fVec2[0];
		fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
		fRec20[1] = fRec20[0];
		fVec1[1] = fVec1[0];
		fRec21[2] = fRec21[1]; fRec21[1] = fRec21[0];
		fRec22[1] = fRec22[0];
		fRec11[2] = fRec11[1]; fRec11[1] = fRec11[0];
		fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
		fRec13[2] = fRec13[1]; fRec13[1] = fRec13[0];
		fRec14[1] = fRec14[0];
		fRec15[1] = fRec15[0];
		fVec0[1] = fVec0[0];
		fRec16[2] = fRec16[1]; fRec16[1] = fRec16[0];
		fRec3[1] = fRec3[0];
	}
}

static struct RegisterParams { RegisterParams(); } RegisterParams;
RegisterParams::RegisterParams()
{
	registerInit("amp", init);
}

} // end namespace gxamp2
