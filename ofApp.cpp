#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofBeginShape();
	for (int i = 0; i < 9; i++) {

		auto noise_seed = ofRandom(1000);

		for (int deg = 0; deg < 360; deg += 1) {

			auto radius = ofMap(ofNoise(noise_seed, cos(deg * DEG_TO_RAD) * 0.25, sin(deg * DEG_TO_RAD) * 0.25, ofGetFrameNum() * 0.02), 0, 1, 170, 270);			auto vertex = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			ofVertex(vertex);

		}

		if (i % 2 == 1) {

			ofNextContour(true);
		}
		else {

			ofNextContour(false);
		}
	}
	ofEndShape();

	/*
	int start = 150;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}