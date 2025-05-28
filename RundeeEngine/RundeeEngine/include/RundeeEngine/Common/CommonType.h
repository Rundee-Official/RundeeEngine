//Project Name: RundeeEngine
//File Name: CommonType.h
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.28
//Description: CommonType classes header file

#pragma once

namespace RundeeEngine {
	struct Vec2 
	{
		float x, y;
		Vec2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

		bool operator==(const Vec2& other) const;
		bool operator!=(const Vec2& other) const;

		Vec2 operator+(const Vec2& other) const;
		Vec2 operator-(const Vec2& other) const;
		Vec2 operator*(float scalar) const;
		Vec2 operator/(float scalar) const;
		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(float scalar);
		Vec2& operator/=(float scalar);

		float Length() const;
		float LengthSquared() const;
		Vec2 Normalize() const;

		float Dot(const Vec2& other) const;
		float Cross(const Vec2& other) const;
		float Distance(const Vec2& other) const;
		float DistanceSquared(const Vec2& other) const;

		Vec2 Perpendicular() const;
		Vec2 Rotate(float angle) const;
		Vec2 Lerp(const Vec2& other, float t) const;
		Vec2 Clamp(const Vec2& min, const Vec2& max) const;
		Vec2 Reflect(const Vec2& normal) const;
		Vec2 Project(const Vec2& other) const;
		Vec2 RotateAround(const Vec2& point, float angle) const;
		Vec2 operator-() const;
		Vec2 operator*(const Vec2& other) const;
		Vec2 operator/(const Vec2& other) const;
		Vec2& operator*=(const Vec2& other);
		Vec2& operator/=(const Vec2& other);

		bool IsZero() const;
		bool IsEqual(const Vec2& other, float epsilon) const;

		float Angle() const;
		float Angle(const Vec2& other) const;
		float AngleDeg() const;
		float AngleDeg(const Vec2& other) const;
		float AngleRad() const;
		float AngleRad(const Vec2& other) const;
		float DistanceToLine(const Vec2& lineStart, const Vec2& lineEnd) const;
		float DistanceToLineSquared(const Vec2& lineStart, const Vec2& lineEnd) const;
		float AngleToLine(const Vec2& lineStart, const Vec2& lineEnd)const;
		float AngleToLineDeg(const Vec2& lineStart, const Vec2& lineEnd) const;
		float AngleToLineRad(const Vec2& lineStart, const Vec2& lineEnd) const;
	};

	struct Vec3
	{
		float x, y, z;
		Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

		bool operator==(const Vec3& other) const;
		bool operator!=(const Vec3& other) const;
		Vec3 operator+(const Vec3& other) const;
		Vec3 operator-(const Vec3& other) const;
		Vec3 operator*(float scalar) const;
		Vec3 operator/(float scalar) const;
		Vec3& operator+=(const Vec3& other);
		Vec3& operator-=(const Vec3& other);
		Vec3& operator*=(float scalar);
		Vec3& operator/=(float scalar);
		float Length() const;
		float LengthSquared() const;
		Vec3 Normalize() const;
		float Dot(const Vec3& other) const;
		Vec3 Cross(const Vec3& other) const;
		float Distance(const Vec3& other) const;
		float DistanceSquared(const Vec3& other) const;
		Vec3 Perpendicular() const;
		Vec3 Rotate(float angle, const Vec3& axis) const;
		Vec3 Lerp(const Vec3& other, float t) const;
		Vec3 Clamp(const Vec3& min, const Vec3& max) const;
		Vec3 Reflect(const Vec3& normal) const;
		Vec3 Project(const Vec3& other) const;
		Vec3 RotateAround(const Vec3& point, float angle, const Vec3& axis) const;
		Vec3 operator-() const;
		Vec3 operator*(const Vec3& other) const;
		Vec3 operator/(const Vec3& other) const;
		Vec3& operator*=(const Vec3& other);
		Vec3& operator/=(const Vec3& other);
		bool IsZero() const;
		bool IsEqual(const Vec3& other, float epsilon = 1e-6f) const;
		float Angle() const;
		float Angle(const Vec3& other) const;
		float AngleDeg() const;
		float AngleDeg(const Vec3& other) const;
		float AngleRad() const;
		float AngleRad(const Vec3& other) const;
		float DistanceToLine(const Vec3& lineStart, const Vec3& lineEnd) const;
		float DistanceToLineSquared(const Vec3& lineStart, const Vec3& lineEnd) const;
		float AngleToLine(const Vec3& lineStart, const Vec3& lineEnd) const;
		float AngleToLineDeg(const Vec3& lineStart, const Vec3& lineEnd) const;
		float AngleToLineRad(const Vec3& lineStart, const Vec3& lineEnd) const;
		float DistanceToPlane(const Vec3& planePoint, const Vec3& planeNormal) const;
		float DistanceToPlaneSquared(const Vec3& planePoint, const Vec3& planeNormal) const;
		float AngleToPlane(const Vec3& planeNormal) const;
		float AngleToPlaneDeg(const Vec3& planeNormal) const;
		float AngleToPlaneRad(const Vec3& planeNormal) const;
		Vec3 ProjectOntoPlane(const Vec3& planePoint, const Vec3& planeNormal) const;
		Vec3 ReflectAcrossPlane(const Vec3& planePoint, const Vec3& planeNormal) const;
	};
}