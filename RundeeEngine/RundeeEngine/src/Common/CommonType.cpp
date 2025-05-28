//Project Name: RundeeEngine
//File Name: CommonType.h
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.28
//Description: CommonType classes source file

#include "../../include/RundeeEngine/Common/CommonType.h"
#include <cstdint>
#include <cmath>

namespace RundeeEngine 
{
	//----------Vec2 Implementation----------

	bool Vec2::operator==(const Vec2& other) const
	{
		return x == other.x && y == other.y;
	}

	bool Vec2::operator!=(const Vec2& other) const
	{
		return !(*this == other);
	}

	Vec2 Vec2::operator+(const Vec2& other) const
	{
		return Vec2(x + other.x, y + other.y);
	}

	Vec2 Vec2::operator-(const Vec2& other) const
	{
		return Vec2(x - other.x, y - other.y);
	}

	Vec2 Vec2::operator*(float scalar) const
	{
		return Vec2(x * scalar, y * scalar);
	}

	Vec2 Vec2::operator/(float scalar) const
	{
		if (scalar != 0.0f)
		{
			return Vec2(x / scalar, y / scalar);
		}
		else
		{
			return Vec2(0.0f, 0.0f);

		}
	}

	Vec2& Vec2::operator+=(const Vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2& Vec2::operator-=(const Vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vec2& Vec2::operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vec2& Vec2::operator/=(float scalar)
	{
		if (scalar != 0.0f)
		{
			x /= scalar;
			y /= scalar;
		}
		else
		{
			x = 0.0f;
			y = 0.0f;
		}
		return *this;
	}

	float Vec2::Length() const
	{
		return sqrtf(x * x + y * y);
	}

	float Vec2::LengthSquared() const
	{
		return x * x + y * y;
	}

	Vec2 Vec2::Normalize() const
	{
		float len = Length();
		if (len > 0.0f)
		{
			return Vec2(x / len, y / len);
		}
		return Vec2(0.0f, 0.0f);
	}

	float Vec2::Dot(const Vec2& other) const
	{
		return x * other.x + y * other.y;
	}

	float Vec2::Cross(const Vec2& other) const
	{
		return x * other.y - y * other.x;
	}

	float Vec2::Distance(const Vec2& other) const
	{
		return sqrtf((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}

	float Vec2::DistanceSquared(const Vec2& other) const
	{
		return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
	}

	Vec2 Vec2::Perpendicular() const
	{
		return Vec2(-y, x);
	}

	Vec2 Vec2::Rotate(float angle) const
	{
		float rad = angle * (3.14159265358979323846f / 180.0f);
		float cosA = cosf(rad);
		float sinA = sinf(rad);
		return Vec2(x * cosA - y * sinA, x * sinA + y * cosA);
	}

	Vec2 Vec2::Lerp(const Vec2& other, float t) const
	{
		return Vec2(x + t * (other.x - x), y + t * (other.y - y));
	}

	Vec2 Vec2::Clamp(const Vec2& min, const Vec2& max) const
	{
		return Vec2(fmaxf(min.x, fminf(x, max.x)), fmaxf(min.y, fminf(y, max.y)));
	}

	Vec2 Vec2::Reflect(const Vec2& normal) const
	{
		float dot = Dot(normal);
		return Vec2(x - 2.0f * dot * normal.x, y - 2.0f * dot * normal.y);
	}

	Vec2 Vec2::Project(const Vec2& other) const
	{
		float dot = Dot(other);
		float lenSquared = other.LengthSquared();
		if (lenSquared > 0.0f)
		{
			return other * (dot / lenSquared);
		}
		return Vec2(0.0f, 0.0f);
	}

	Vec2 Vec2::RotateAround(const Vec2& point, float angle) const
	{
		float rad = angle * (3.14159265358979323846f / 180.0f);
		float cosA = cosf(rad);
		float sinA = sinf(rad);
		float dx = x - point.x;
		float dy = y - point.y;
		return Vec2(point.x + dx * cosA - dy * sinA, point.y + dx * sinA + dy * cosA);
	}

	Vec2 Vec2::operator-() const
	{
		return Vec2(-x, -y);
	}

	Vec2 Vec2::operator*(const Vec2& other) const
	{
		return Vec2(x * other.x, y * other.y);
	}

	Vec2 Vec2::operator/(const Vec2& other) const
	{
		return Vec2((other.x != 0.0f) ? x / other.x : 0.0f, (other.y != 0.0f) ? y / other.y : 0.0f);
	}

	Vec2& Vec2::operator*=(const Vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vec2& Vec2::operator/=(const Vec2& other)
	{
		if (other.x != 0.0f && other.y != 0.0f)
		{
			x /= other.x;
			y /= other.y;
		}
		else
		{
			x = 0.0f;
			y = 0.0f;
		}
		return *this;
	}

	bool Vec2::IsZero() const
	{
		return x == 0.0f && y == 0.0f;
	}

	bool Vec2::IsEqual(const Vec2& other, float epsilon = 1e-6f) const
	{
		return fabsf(x - other.x) < epsilon && fabsf(y - other.y) < epsilon;
	}

	float Vec2::Angle() const
	{
		return atan2f(y, x) * (180.0f / 3.14159265358979323846f);
	}

	float Vec2::Angle(const Vec2& other) const
	{
		float dot = Dot(other);
		float len1 = Length();
		float len2 = other.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec2::AngleDeg() const
	{
		return atan2f(y, x) * (180.0f / 3.14159265358979323846f);
	}

	float Vec2::AngleDeg(const Vec2& other) const
	{
		float dot = Dot(other);
		float len1 = Length();
		float len2 = other.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec2::AngleRad() const
	{
		return atan2f(y, x);
	}

	float Vec2::AngleRad(const Vec2& other) const
	{
		float dot = Dot(other);
		float len1 = Length();
		float len2 = other.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2));
		}
		return 0.0f;
	}

	float Vec2::DistanceToLine(const Vec2& lineStart, const Vec2& lineEnd) const
	{
		Vec2 lineDir = lineEnd - lineStart;
		Vec2 pointDir = *this - lineStart;
		float lineLengthSquared = lineDir.LengthSquared();
		if (lineLengthSquared == 0.0f)
		{
			return pointDir.Length();
		}
		float t = fmaxf(0.0f, fminf(1.0f, pointDir.Dot(lineDir) / lineLengthSquared));
		Vec2 projection = lineStart + lineDir * t;
		return (*this - projection).Length();
	}

	float Vec2::DistanceToLineSquared(const Vec2& lineStart, const Vec2& lineEnd) const
	{
		Vec2 lineDir = lineEnd - lineStart;
		Vec2 pointDir = *this - lineStart;
		float lineLengthSquared = lineDir.LengthSquared();
		if (lineLengthSquared == 0.0f)
		{
			return pointDir.LengthSquared();
		}
		float t = fmaxf(0.0f, fminf(1.0f, pointDir.Dot(lineDir) / lineLengthSquared));
		Vec2 projection = lineStart + lineDir * t;
		return (*this - projection).LengthSquared();
	}

	float Vec2::AngleToLine(const Vec2& lineStart, const Vec2& lineEnd) const
	{
		Vec2 lineDir = lineEnd - lineStart;
		float dot = Dot(lineDir);
		float len1 = Length();
		float len2 = lineDir.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec2::AngleToLineDeg(const Vec2& lineStart, const Vec2& lineEnd) const
	{
		Vec2 lineDir = lineEnd - lineStart;
		float dot = Dot(lineDir);
		float len1 = Length();
		float len2 = lineDir.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec2::AngleToLineRad(const Vec2& lineStart, const Vec2& lineEnd) const
	{
		Vec2 lineDir = lineEnd - lineStart;
		float dot = Dot(lineDir);
		float len1 = Length();
		float len2 = lineDir.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2));
		}
		return 0.0f;
	}

	//----------Vec3 Implementation----------

	bool Vec3::operator==(const Vec3& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	bool Vec3::operator!=(const Vec3& other) const
	{
		return !(*this == other);
	}

	Vec3 Vec3::operator+(const Vec3& other) const
	{
		return Vec3(x + other.x, y + other.y, z + other.z);
	}

	Vec3 Vec3::operator-(const Vec3& other) const
	{
		return Vec3(x - other.x, y - other.y, z - other.z);
	}

	Vec3 Vec3::operator*(float scalar) const
	{
		return Vec3(x * scalar, y * scalar, z * scalar);
	}

	Vec3 Vec3::operator/(float scalar) const
	{
		if (scalar != 0.0f)
		{
			return Vec3(x / scalar, y / scalar, z / scalar);
		}
		else
		{
			return Vec3(0.0f, 0.0f, 0.0f);
		}
	}

	Vec3& Vec3::operator+=(const Vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vec3& Vec3::operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	Vec3& Vec3::operator/=(float scalar)
	{
		if (scalar != 0.0f)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
		}
		else
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}
		return *this;
	}

	float Vec3::Length() const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	float Vec3::LengthSquared() const
	{
		return x * x + y * y + z * z;
	}

	Vec3 Vec3::Normalize() const
	{
		float len = Length();
		if (len > 0.0f)
		{
			return Vec3(x / len, y / len, z / len);
		}
		return Vec3(0.0f, 0.0f, 0.0f);
	}

	float Vec3::Dot(const Vec3& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vec3 Vec3::Cross(const Vec3& other) const
	{
		return Vec3(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}

	float Vec3::Distance(const Vec3& other) const
	{
		return sqrtf((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
	}

	float Vec3::DistanceSquared(const Vec3& other) const
	{
		return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z);
	}

	Vec3 Vec3::Perpendicular() const
	{
		if (fabsf(x) > fabsf(y) && fabsf(x) > fabsf(z))
		{
			return Vec3(0.0f, z, -y).Normalize();
		}
		else if (fabsf(y) > fabsf(z))
		{
			return Vec3(-z, 0.0f, x).Normalize();
		}
		else
		{
			return Vec3(y, -x, 0.0f).Normalize();
		}
	}

	Vec3 Vec3::Rotate(float angle, const Vec3& axis) const
	{
		float rad = angle * (3.14159265358979323846f / 180.0f);
		float cosA = cosf(rad);
		float sinA = sinf(rad);
		float dot = Dot(axis);
		Vec3 cross = Cross(axis);
		return Vec3(
			x * cosA + cross.x * sinA + axis.x * dot * (1 - cosA),
			y * cosA + cross.y * sinA + axis.y * dot * (1 - cosA),
			z * cosA + cross.z * sinA + axis.z * dot * (1 - cosA)
		);
	}

	Vec3 Vec3::Lerp(const Vec3& other, float t) const
	{
		return Vec3(x + t * (other.x - x), y + t * (other.y - y), z + t * (other.z - z));
	}

	Vec3 Vec3::Clamp(const Vec3& min, const Vec3& max) const
	{
		return Vec3(fmaxf(min.x, fminf(x, max.x)), fmaxf(min.y, fminf(y, max.y)), fmaxf(min.z, fminf(z, max.z)));
	}

	Vec3 Vec3::Reflect(const Vec3& normal) const
	{
		float dot = Dot(normal);
		return Vec3(x - 2.0f * dot * normal.x, y - 2.0f * dot * normal.y, z - 2.0f * dot * normal.z);
	}

	Vec3 Vec3::Project(const Vec3& other) const
	{
		float dot = Dot(other);
		float lenSquared = other.LengthSquared();
		if (lenSquared > 0.0f)
		{
			return other * (dot / lenSquared);
		}
		return Vec3(0.0f, 0.0f, 0.0f);
	}

	Vec3 Vec3::RotateAround(const Vec3& point, float angle, const Vec3& axis) const
	{
		float rad = angle * (3.14159265358979323846f / 180.0f);
		float cosA = cosf(rad);
		float sinA = sinf(rad);
		float dx = x - point.x;
		float dy = y - point.y;
		float dz = z - point.z;
		return Vec3(
			point.x + (dx * (cosA + axis.x * axis.x * (1 - cosA)) + dy * (axis.x * axis.y * (1 - cosA) - axis.z * sinA) + dz * (axis.x * axis.z * (1 - cosA) + axis.y * sinA)),
			point.y + (dx * (axis.y * axis.x * (1 - cosA) + axis.z * sinA) + dy * (cosA + axis.y * axis.y * (1 - cosA)) + dz * (axis.y * axis.z * (1 - cosA) - axis.x * sinA)),
			point.z + (dx * (axis.z * axis.x * (1 - cosA) - axis.y * sinA) + dy * (axis.z * axis.y * (1 - cosA) + axis.x * sinA) + dz * (cosA + axis.z * axis.z * (1 - cosA)))
		);
	}

	Vec3 Vec3::operator-() const
	{
		return Vec3(-x, -y, -z);
	}

	Vec3 Vec3::operator*(const Vec3& other) const
	{
		return Vec3(x * other.x, y * other.y, z * other.z);
	}

	Vec3 Vec3::operator/(const Vec3& other) const
	{
		return Vec3((other.x != 0.0f) ? x / other.x : 0.0f, (other.y != 0.0f) ? y / other.y : 0.0f, (other.z != 0.0f) ? z / other.z : 0.0f);
	}

	Vec3& Vec3::operator*=(const Vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vec3& Vec3::operator/=(const Vec3& other)
	{
		if (other.x != 0.0f && other.y != 0.0f && other.z != 0.0f)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
		}
		else
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}
		return *this;
	}

	bool Vec3::IsZero() const
	{
		return x == 0.0f && y == 0.0f && z == 0.0f;
	}

	bool Vec3::IsEqual(const Vec3& other, float epsilon) const
	{
		return fabsf(x - other.x) < epsilon && fabsf(y - other.y) < epsilon && fabsf(z - other.z) < epsilon;
	}

	float Vec3::Angle() const
	{
		return atan2f(sqrtf(x * x + y * y), z) * (180.0f / 3.14159265358979323846f);
	}

	float Vec3::Angle(const Vec3& other) const
	{
		float dot = Dot(other);
		float len1 = Length();
		float len2 = other.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec3::AngleDeg() const
	{
		return atan2f(sqrtf(x * x + y * y), z) * (180.0f / 3.14159265358979323846f);
	}

	float Vec3::AngleDeg(const Vec3& other) const
	{
		float dot = Dot(other);
		float len1 = Length();
		float len2 = other.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec3::AngleRad() const
	{
		return atan2f(sqrtf(x * x + y * y), z);
	}

	float Vec3::AngleRad(const Vec3& other) const
	{
		float dot = Dot(other);
		float len1 = Length();
		float len2 = other.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2));
		}
		return 0.0f;
	}

	float Vec3::DistanceToLine(const Vec3& lineStart, const Vec3& lineEnd) const
	{
		Vec3 lineDir = lineEnd - lineStart;
		Vec3 pointDir = *this - lineStart;
		float lineLengthSquared = lineDir.LengthSquared();
		if (lineLengthSquared == 0.0f)
		{
			return pointDir.Length();
		}
		float t = fmaxf(0.0f, fminf(1.0f, pointDir.Dot(lineDir) / lineLengthSquared));
		Vec3 projection = lineStart + lineDir * t;
		return (*this - projection).Length();
	}

	float Vec3::DistanceToLineSquared(const Vec3& lineStart, const Vec3& lineEnd) const
	{
		Vec3 lineDir = lineEnd - lineStart;
		Vec3 pointDir = *this - lineStart;
		float lineLengthSquared = lineDir.LengthSquared();
		if (lineLengthSquared == 0.0f)
		{
			return pointDir.LengthSquared();
		}
		float t = fmaxf(0.0f, fminf(1.0f, pointDir.Dot(lineDir) / lineLengthSquared));
		Vec3 projection = lineStart + lineDir * t;
		return (*this - projection).LengthSquared();
	}

	float Vec3::AngleToLine(const Vec3& lineStart, const Vec3& lineEnd) const
	{
		Vec3 lineDir = lineEnd - lineStart;
		float dot = Dot(lineDir);
		float len1 = Length();
		float len2 = lineDir.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec3::AngleToLineDeg(const Vec3& lineStart, const Vec3& lineEnd) const
	{
		Vec3 lineDir = lineEnd - lineStart;
		float dot = Dot(lineDir);
		float len1 = Length();
		float len2 = lineDir.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec3::AngleToLineRad(const Vec3& lineStart, const Vec3& lineEnd) const
	{
		Vec3 lineDir = lineEnd - lineStart;
		float dot = Dot(lineDir);
		float len1 = Length();
		float len2 = lineDir.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2));
		}
		return 0.0f;
	}

	float Vec3::DistanceToPlane(const Vec3& planePoint, const Vec3& planeNormal) const
	{
		float d = planeNormal.Dot(*this - planePoint);
		return fabsf(d);
	}

	float Vec3::DistanceToPlaneSquared(const Vec3& planePoint, const Vec3& planeNormal) const
	{
		float d = planeNormal.Dot(*this - planePoint);
		return d * d;
	}

	float Vec3::AngleToPlane(const Vec3& planeNormal) const
	{
		float dot = Dot(planeNormal);
		float len1 = Length();
		float len2 = planeNormal.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec3::AngleToPlaneDeg(const Vec3& planeNormal) const
	{
		float dot = Dot(planeNormal);
		float len1 = Length();
		float len2 = planeNormal.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2)) * (180.0f / 3.14159265358979323846f);
		}
		return 0.0f;
	}

	float Vec3::AngleToPlaneRad(const Vec3& planeNormal) const
	{
		float dot = Dot(planeNormal);
		float len1 = Length();
		float len2 = planeNormal.Length();
		if (len1 > 0.0f && len2 > 0.0f)
		{
			return acosf(dot / (len1 * len2));
		}
		return 0.0f;
	}

	Vec3 Vec3::ProjectOntoPlane(const Vec3& planePoint, const Vec3& planeNormal) const
	{
		float d = planeNormal.Dot(*this - planePoint);
		return *this - planeNormal * d;
	}

	Vec3 Vec3::ReflectAcrossPlane(const Vec3& planePoint, const Vec3& planeNormal) const
	{
		float d = planeNormal.Dot(*this - planePoint);
		return *this - planeNormal * (2.0f * d);
	}
}