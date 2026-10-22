#include <SDL.h>
#include <iostream>
#include "MathManager.h"
#include <cmath>

MathManager::MathManager() {

}

int MathManager::GenerateRandomRange(int min, int range) {
  int variable = min + rand() % range;
  //std::cout << "random number is " << variable << std::endl;
  return variable;
}

int MathManager::GenerateRandomRangeWithSeed(int min, int range, int seed) {
  srand(seed);
  int variable = min + rand() % range;
  //std::cout << "random number is " << variable << std::endl;
  return variable;
}

//i had once created a physics manager in c# and wanted to recreate for this game engine, didn't get to it yet so what's below is unfinished

// + operator
MathManager::Vec2 MathManager::Plus(Vec2& left, Vec2& right) {
  return Vec2(left.x + right.x, left.y + right.y);
}

// - operator
MathManager::Vec2 MathManager::Minus(Vec2& left, Vec2& right) {
  return Vec2(left.x - right.x, left.y - right.y);
}

// * operator
MathManager::Vec2 MathManager::Multiply(Vec2& left, Vec2& right) {
  return Vec2(left.x * right.x, left.y * right.y);
}

//// * scalar and vector
//public static Vec2 operator *(float scalar, Vec2 vector) {
//	return new Vec2(vector.x * scalar, vector.y * scalar);
//}
//
//// * vector and scalar
//public static Vec2 operator *(Vec2 vector, float scalar) {
//	return new Vec2(vector.x * scalar, vector.y * scalar);
//}
//
//length
float MathManager::GetLength(const Vec2& vector2) {
  return std::sqrt((vector2.x * vector2.x) + (vector2.y * vector2.y));
}
//
////normalize
//public void Normalize() {
//	float length = Length();
//	x /= length;
//	y /= length;
//}
//
////normalized
//public Vec2 Normalized() {
//	Vec2 normalized = new Vec2(x, y);
//	normalized.Normalize();
//	return normalized;
//}
//
////set XY
//public void SetXY(float pX, float pY) {
//	x = pX;
//	y = pY;
//}
//
////To string
//public override string ToString() {
//	return String.Format("({0},{1})", x, y);
//}
//
////Deg 2 Rad
//public static float Deg2Rad(float degrees) {
//	return degrees * (Mathf.PI / 180);
//}
//
////Rad 2 Deg
//public static float Rad2Deg(float radians) {
//	return radians * (180 / Mathf.PI);
//}
//
////get unit vector Deg
//public static Vec2 GetUnitVectorDeg(float angleDeg) {
//	return new Vec2(Mathf.Cos(Deg2Rad(angleDeg)), Mathf.Sin(Deg2Rad(angleDeg)));
//}
//
////get unit vector Rad
//public static Vec2 GetUnitVectorRad(float angleRad) {
//	return new Vec2(Mathf.Cos(angleRad), Mathf.Sin(angleRad));
//}
//
////get random unit vector
//public static Vec2 RandomUnitVector() {
//	int randomDegree = Utils.Random(0, 360);
//	return GetUnitVectorDeg((float)randomDegree);
//}
//
////set angle Degree
//public void SetAngleDegrees(float angleDeg) {
//	this = GetUnitVectorDeg(angleDeg) * Length();
//}
//
////set angle Radians
//public void SetAngleRadians(float angleRad) {
//	this = GetUnitVectorRad(angleRad) * Length();
//}
//
////get angle radians
//public float GetAngleRadians() {
//	return (Mathf.Atan2(y, x));
//}
//
////get angle degrees
//public float GetAngleDegrees() {
//	return (Rad2Deg(GetAngleRadians()));
//}
//
////rotate degrees
//public void RotateDegrees(float degree) {
//	float newX = x * Mathf.Cos(Deg2Rad(degree)) - y * Mathf.Sin(Deg2Rad(degree));
//	float newY = x * Mathf.Sin(Deg2Rad(degree)) + y * Mathf.Cos(Deg2Rad(degree));
//	x = newX;
//	y = newY;
//}
//
////rotate radians
//public void RotateRadians(float radians) {
//	float newX = x * Mathf.Cos(radians) - y * Mathf.Sin(radians);
//	float newY = x * Mathf.Sin(radians) + y * Mathf.Cos(radians);
//	x = newX;
//	y = newY;
//}
//
////rotate around degrees
//public void RotateAroundDegrees(float degree, Vec2 point) {
//	this -= point;
//	RotateDegrees(degree);
//	this += point;
//}
//
////rotate around radians
//public void RotateAroundRadians(float radians, Vec2 point) {
//	this -= point;
//	RotateRadians(radians);
//	this += point;
//}
//
////dot
//public float Dot(Vec2 other) {
//	float vectorsX = x * other.x;
//	//Console.WriteLine("vectors X times each other: " + vectorsX);
//	float vectorsY = y * other.y;
//	//Console.WriteLine("vectors Y times each other: " + vectorsY);
//	float finalDot = vectorsX + vectorsY;
//	return (finalDot);
//}
//
////normal
//public Vec2 Normal() {
//	// TODO: return a unit normal
//	return new Vec2(-y, x).Normalized();
//}
//
////reflect
//public Vec2 Reflect(Vec2 normal, float bounciness = 1) {
//	normal.Normalize();
//	this -= (1 + bounciness) * (this.Dot(normal) * normal);
//	return this;
//}