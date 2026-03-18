#pragma once

#include "Utils/Morph.h"
#include "../../../Utils/Math/Rotation.h"
#include "../../../Scene/Materials/Static/SimpleMaterial.h"
#include "../../../Scene/Objects/Object3D.h"
#include "../../../Renderer/Utils/IndexGroup.h"

class RhaskyProtoV3CustomExpression{
public:
    enum Morphs {
        AddEyebrow,
        MouthFrown,
        EyeFrown,
        AltNose,
        POG,
        AlmondEyes,
        AngryEyes,
        HappySquint
    };

private:
    Vector3D* basisVertices = new Vector3D[33] {Vector3D(142.0465f,81.8757f,0.2350f),Vector3D(101.1571f,96.1396f,0.2039f),Vector3D(123.1562f,82.9103f,0.2350f),Vector3D(133.5642f,102.9256f,0.2350f),Vector3D(87.2987f,70.7395f,0.2350f),Vector3D(92.8581f,85.4939f,0.2350f),Vector3D(117.0182f,103.1925f,0.2350f),Vector3D(109.6740f,90.1348f,0.2350f),Vector3D(129.3566f,92.8118f,0.2350f),Vector3D(146.7509f,95.2291f,0.2350f),Vector3D(104.3418f,79.8412f,0.2350f),Vector3D(160.4085f,75.6886f,0.2350f),Vector3D(31.0627f,19.4793f,0.2350f),Vector3D(55.8724f,40.2722f,0.2350f),Vector3D(59.6530f,33.4200f,0.2350f),Vector3D(94.2036f,14.9372f,0.2350f),Vector3D(93.5680f,22.9147f,0.2350f),Vector3D(113.5824f,24.9419f,0.2350f),Vector3D(128.8840f,29.8757f,0.1047f),Vector3D(146.1327f,33.4200f,0.2350f),Vector3D(140.9344f,37.9094f,0.1705f),Vector3D(18.7760f,22.0784f,0.2350f),Vector3D(152.5123f,46.4156f,0.2350f),Vector3D(26.3235f,28.5648f,0.2350f),Vector3D(12.5599f,34.5396f,0.2350f),Vector3D(109.0362f,32.4749f,0.1639f),Vector3D(130.7743f,23.0235f,0.2350f),Vector3D(12.6371f,52.0129f,0.2350f),Vector3D(18.9929f,66.8431f,0.2350f),Vector3D(24.5013f,61.7585f,0.2350f),Vector3D(37.6367f,74.0464f,0.2350f),Vector3D(42.0858f,65.9957f,0.2350f),Vector3D(58.9986f,65.2066f,0.2350f)};
    IndexGroup* basisIndexes = new IndexGroup[29] {IndexGroup(7,8,6),IndexGroup(8,9,3),IndexGroup(2,8,7),IndexGroup(1,7,6),IndexGroup(6,8,3),IndexGroup(1,5,7),IndexGroup(5,10,7),IndexGroup(5,4,10),IndexGroup(2,0,8),IndexGroup(10,2,7),IndexGroup(8,0,9),IndexGroup(0,11,9),IndexGroup(14,13,12),IndexGroup(14,15,13),IndexGroup(15,16,13),IndexGroup(15,17,16),IndexGroup(16,17,25),IndexGroup(20,18,19),IndexGroup(17,18,25),IndexGroup(13,23,12),IndexGroup(19,22,20),IndexGroup(23,21,12),IndexGroup(23,24,21),IndexGroup(17,26,18),IndexGroup(18,26,19),IndexGroup(29,28,27),IndexGroup(29,30,28),IndexGroup(31,30,29),IndexGroup(31,32,30)};
    StaticTriangleGroup<33,29> triangleGroup = StaticTriangleGroup<33,29>(&basisVertices[0], &basisIndexes[0]);
    TriangleGroup<33,29> triangleGroupMemory = TriangleGroup<33,29>(&triangleGroup);
    SimpleMaterial simpleMaterial = SimpleMaterial(RGBColor(128, 128, 128));
    Object3D basisObj = Object3D(&triangleGroup, &triangleGroupMemory, &simpleMaterial);

    static const uint8_t morphCount = 8;
    int* AddEyebrowIndexes = new int[12] {0,1,2,3,4,5,6,7,8,9,10,11};
    int* MouthFrownIndexes = new int[11] {13,14,15,16,17,18,19,20,22,25,26};
    int* EyeFrownIndexes = new int[10] {0,1,2,3,6,7,8,9,10,11};
    int* AltNoseIndexes = new int[6] {27,28,29,30,31,32};
    int* POGIndexes = new int[15] {12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    int* AlmondEyesIndexes = new int[8] {0,2,4,7,8,9,10,11};
    int* AngryEyesIndexes = new int[11] {0,1,2,3,4,5,6,7,9,10,11};
    int* HappySquintIndexes = new int[7] {0,2,4,7,8,10,11};

    Vector3D* AddEyebrowVectors = new Vector3D[12] {Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f),Vector3D(-3.5442f,-12.7593f,0.0000f)};
    Vector3D* MouthFrownVectors = new Vector3D[11] {Vector3D(0.9451f,-9.4513f,0.0000f),Vector3D(-2.5991f,-8.5062f,0.0000f),Vector3D(-8.0336f,-2.3628f,0.0000f),Vector3D(-6.3797f,-4.2531f,0.0000f),Vector3D(-12.7593f,-7.0885f,0.0000f),Vector3D(-13.9407f,-15.5947f,0.0000f),Vector3D(-18.4301f,-22.4469f,0.0000f),Vector3D(-13.4682f,-21.0292f,0.0000f),Vector3D(-14.4133f,-39.2230f,0.0000f),Vector3D(-8.0336f,-9.9239f,0.0000f),Vector3D(-19.1389f,-15.3584f,0.0000f)};
    Vector3D* EyeFrownVectors = new Vector3D[10] {Vector3D(-4.7257f,-9.6876f,0.0000f),Vector3D(-0.2363f,-1.6540f,0.0000f),Vector3D(-4.2531f,-12.2867f,0.0000f),Vector3D(-4.4440f,-15.1605f,0.0000f),Vector3D(-3.7805f,-11.8142f,0.0000f),Vector3D(-4.0168f,-7.0885f,0.0000f),Vector3D(-3.5442f,-10.8690f,0.0000f),Vector3D(2.5991f,-8.0336f,0.0000f),Vector3D(-3.7805f,-9.9239f,0.0000f),Vector3D(-2.8354f,0.0000f,0.0000f)};
    Vector3D* AltNoseVectors = new Vector3D[6] {Vector3D(5.4345f,-3.3080f,0.0000f),Vector3D(-6.8522f,-2.3628f,0.0000f),Vector3D(-6.1434f,-1.8903f,0.0000f),Vector3D(-25.4960f,-9.5661f,0.0000f),Vector3D(-23.7278f,-6.1275f,0.0000f),Vector3D(-28.8266f,3.3080f,0.0000f)};
    Vector3D* POGVectors = new Vector3D[15] {Vector3D(-3.3080f,-2.3628f,0.0000f),Vector3D(-27.4089f,-4.7257f,0.0000f),Vector3D(-24.1009f,-17.9575f,0.0000f),Vector3D(-50.5646f,5.1982f,0.0000f),Vector3D(-60.0160f,20.3204f,0.0000f),Vector3D(-66.6319f,-1.6540f,0.0000f),Vector3D(-80.1000f,6.8522f,0.0000f),Vector3D(-87.4248f,2.3628f,0.0000f),Vector3D(-89.3151f,0.7088f,0.0000f),Vector3D(5.6267f,-12.4503f,0.0000f),Vector3D(-95.9310f,-2.8354f,0.0000f),Vector3D(-7.7838f,16.4331f,0.0000f),Vector3D(-6.3642f,8.5206f,0.0000f),Vector3D(-66.6319f,7.7973f,0.0000f),Vector3D(-77.2646f,2.3628f,0.0000f)};
    Vector3D* AlmondEyesVectors = new Vector3D[8] {Vector3D(-1.4177f,-1.4177f,0.0000f),Vector3D(-1.4177f,-9.2150f,0.0000f),Vector3D(0.4726f,2.1266f,0.0000f),Vector3D(0.2363f,-3.0717f,0.0000f),Vector3D(-0.4726f,-3.0717f,0.0000f),Vector3D(-1.4177f,3.5442f,0.0000f),Vector3D(0.7088f,-8.2699f,0.0000f),Vector3D(-5.1982f,15.5947f,0.0000f)};
    Vector3D* AngryEyesVectors = new Vector3D[11] {Vector3D(2.8354f,7.0885f,0.0000f),Vector3D(-4.0168f,-5.4345f,0.0000f),Vector3D(7.0885f,-9.2150f,0.0000f),Vector3D(-12.0504f,3.3080f,0.0000f),Vector3D(1.6540f,-1.1814f,0.0000f),Vector3D(-1.1814f,-5.1982f,0.0000f),Vector3D(-6.6159f,-1.8903f,0.0000f),Vector3D(4.4894f,-4.7257f,0.0000f),Vector3D(-12.9956f,12.9956f,0.0000f),Vector3D(3.0717f,-12.0504f,0.0000f),Vector3D(-14.6496f,32.6071f,0.0000f)};
    Vector3D* HappySquintVectors = new Vector3D[7] {Vector3D(-2.4735f,11.2681f,0.0000f),Vector3D(-3.0232f,13.1919f,0.0000f),Vector3D(1.9238f,3.2980f,0.0000f),Vector3D(-2.4735f,5.7715f,0.0000f),Vector3D(-3.2980f,7.1456f,0.0000f),Vector3D(-2.4735f,9.3443f,0.0000f),Vector3D(-1.3742f,2.7483f,0.0000f)};

    Morph morphs[8] = {
        Morph(12, AddEyebrowIndexes, AddEyebrowVectors),
        Morph(11, MouthFrownIndexes, MouthFrownVectors),
        Morph(10, EyeFrownIndexes, EyeFrownVectors),
        Morph(6, AltNoseIndexes, AltNoseVectors),
        Morph(15, POGIndexes, POGVectors),
        Morph(8, AlmondEyesIndexes, AlmondEyesVectors),
        Morph(11, AngryEyesIndexes, AngryEyesVectors),
        Morph(7, HappySquintIndexes, HappySquintVectors)
    };

public:
    RhaskyProtoV3CustomExpression(){}

    Object3D* GetObject(){
        return &basisObj;
    }

    void SetMorphWeight(Morphs morph, float weight){
        morphs[morph].Weight = weight;
    }

    float* GetMorphWeightReference(Morphs morph){
        return &morphs[morph].Weight;
    }

    void Reset(){
        for(int i = 0; i < morphCount; i++){
            morphs[i].Weight = 0.0f;
        }
    }

    void Update(){
        basisObj.ResetVertices();

        for(int i = 0; i < morphCount; i++){
            if(morphs[i].Weight > 0.0f){
                morphs[i].MorphObject3D(basisObj.GetTriangleGroup());
            }
        }

    }
};
