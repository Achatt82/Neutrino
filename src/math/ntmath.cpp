#include "ntmath.h"
#include <cmath>

namespace Math {

	// Utility functions
	inline float DegToRad(float deg) { return deg * (pi / 180.0f); }
	inline float RadToDeg(float rad) { return rad * (180.0f / pi); }

	// ---------------- Vector2 ----------------
	Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}
	Vector2 Vector2::Zeros() { return { 0.0f, 0.0f }; }
	Vector2 Vector2::Ones() { return { 1.0f, 1.0f }; }

	Vector2 Vector2::operator+(const Vector2& v) const { return { x + v.x, y + v.y }; }
	Vector2 Vector2::operator-(const Vector2& v) const { return { x - v.x, y - v.y }; }
	Vector2 Vector2::operator*(float s) const { return { x * s, y * s }; }
	Vector2 Vector2::operator/(float s) const { return { x / s, y / s }; }

	Vector2& Vector2::operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }
	Vector2& Vector2::operator-=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }
	Vector2& Vector2::operator*=(float s) { x *= s; y *= s; return *this; }
	Vector2& Vector2::operator/=(float s) { x /= s; y /= s; return *this; }

	bool Vector2::operator==(const Vector2& v) const { return std::fabs(x - v.x) < epsilon && std::fabs(y - v.y) < epsilon; }
	bool Vector2::operator!=(const Vector2& v) const { return !(*this == v); }

	Vector2 Vector2::operator-() const { return { -x, -y }; }

	float Vector2::Magnitude() const { return std::sqrt(x * x + y * y); }
	float Vector2::SqrMagnitude() const { return x * x + y * y; }
	Vector2 Vector2::Normalized() const { float m = Magnitude(); return m > epsilon ? (*this / m) : Zeros(); }
	float Vector2::Dot(const Vector2& a, const Vector2& b) { return a.x * b.x + a.y * b.y; }
	Vector2 Vector2::Lerp(const Vector2& a, const Vector2& b, float t) { return a * (1 - t) + b * t; }

	// ---------------- Vector3 ----------------
	Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	Vector3 Vector3::Zeros() { return { 0.0f,0.0f,0.0f }; }
	Vector3 Vector3::Ones() { return { 1.0f,1.0f,1.0f }; }

	Vector3 Vector3::operator+(const Vector3& v) const { return { x + v.x, y + v.y, z + v.z }; }
	Vector3 Vector3::operator-(const Vector3& v) const { return { x - v.x, y - v.y, z - v.z }; }
	Vector3 Vector3::operator*(float s) const { return { x * s, y * s, z * s }; }
	Vector3 Vector3::operator/(float s) const { return { x / s, y / s, z / s }; }

	Vector3& Vector3::operator+=(const Vector3& v) { x += v.x; y += v.y; z += v.z; return *this; }
	Vector3& Vector3::operator-=(const Vector3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
	Vector3& Vector3::operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
	Vector3& Vector3::operator/=(float s) { x /= s; y /= s; z /= s; return *this; }

	bool Vector3::operator==(const Vector3& v) const { return std::fabs(x - v.x) < epsilon && std::fabs(y - v.y) < epsilon && std::fabs(z - v.z) < epsilon; }
	bool Vector3::operator!=(const Vector3& v) const { return !(*this == v); }

	Vector3 Vector3::operator-() const { return { -x,-y,-z }; }

	float Vector3::Magnitude() const { return std::sqrt(x * x + y * y + z * z); }
	float Vector3::SqrMagnitude() const { return x * x + y * y + z * z; }
	Vector3 Vector3::Normalized() const { float m = Magnitude(); return m > epsilon ? (*this / m) : Zeros(); }
	float Vector3::Dot(const Vector3& a, const Vector3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
	Vector3 Vector3::Cross(const Vector3& a, const Vector3& b) { return { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x }; }
	Vector3 Vector3::Lerp(const Vector3& a, const Vector3& b, float t) { return a * (1 - t) + b * t; }

	// ---------------- Vector4 ----------------
	Vector4::Vector4(float _x, float _y, float _z, float _w) :x(_x), y(_y), z(_z), w(_w) {}
	Vector4 Vector4::Zeros() { return { 0,0,0,0 }; }
	Vector4 Vector4::Ones() { return { 1,1,1,1 }; }

	Vector4 Vector4::operator+(const Vector4& v) const { return { x + v.x, y + v.y, z + v.z, w + v.w }; }
	Vector4 Vector4::operator-(const Vector4& v) const { return { x - v.x, y - v.y, z - v.z, w - v.w }; }
	Vector4 Vector4::operator*(float s) const { return { x * s, y * s, z * s, w * s }; }
	Vector4 Vector4::operator/(float s) const { return { x / s, y / s, z / s, w / s }; }

	Vector4& Vector4::operator+=(const Vector4& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
	Vector4& Vector4::operator-=(const Vector4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }
	Vector4& Vector4::operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
	Vector4& Vector4::operator/=(float s) { x /= s; y /= s; z /= s; w /= s; return *this; }

	bool Vector4::operator==(const Vector4& v) const { return std::fabs(x - v.x) < epsilon && std::fabs(y - v.y) < epsilon && std::fabs(z - v.z) < epsilon && std::fabs(w - v.w) < epsilon; }
	bool Vector4::operator!=(const Vector4& v) const { return !(*this == v); }

	Vector4 Vector4::operator-() const { return { -x,-y,-z,-w }; }

	float Vector4::Magnitude() const { return std::sqrt(x * x + y * y + z * z + w * w); }
	float Vector4::SqrMagnitude() const { return x * x + y * y + z * z + w * w; }
	Vector4 Vector4::Normalized() const { float m = Magnitude(); return m > epsilon ? (*this / m) : Zeros(); }
	float Vector4::Dot(const Vector4& a, const Vector4& b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
	Vector4 Vector4::Lerp(const Vector4& a, const Vector4& b, float t) { return a * (1 - t) + b * t; }

	// ---------------- Matrix4 ----------------
	Matrix4::Matrix4() { for (int i = 0; i < 16; i++) m[i] = 0; }

	Matrix4 Matrix4::operator*(const Matrix4& mat) const {
		Matrix4 result;
		for (int row = 0; row < 4; ++row)
			for (int col = 0; col < 4; ++col) {
				result.m[row * 4 + col] = 0;
				for (int k = 0; k < 4; ++k)
					result.m[row * 4 + col] += m[row * 4 + k] * mat.m[k * 4 + col];
			}
		return result;
	}

	Vector3 Matrix4::operator*(const Vector3& v) const {
		return {
			m[0] * v.x + m[1] * v.y + m[2] * v.z + m[3],
			m[4] * v.x + m[5] * v.y + m[6] * v.z + m[7],
			m[8] * v.x + m[9] * v.y + m[10] * v.z + m[11]
		};
	}

	Matrix4 Matrix4::Identity() {
		Matrix4 mat;
		mat.m[0] = mat.m[5] = mat.m[10] = mat.m[15] = 1.0f;
		return mat;
	}

	Matrix4 Matrix4::Translate(const Vector3& pos) {
		Matrix4 mat = Identity();
		mat.m[3] = pos.x;
		mat.m[7] = pos.y;
		mat.m[11] = pos.z;
		return mat;
	}

	Matrix4 Matrix4::Scale(const Vector3& scale) {
		Matrix4 mat = Identity();
		mat.m[0] = scale.x;
		mat.m[5] = scale.y;
		mat.m[10] = scale.z;
		return mat;
	}

	Matrix4 Matrix4::RotateX(float angleRad) {
		Matrix4 mat = Identity();
		float c = std::cos(angleRad), s = std::sin(angleRad);
		mat.m[5] = c; mat.m[6] = -s;
		mat.m[9] = s; mat.m[10] = c;
		return mat;
	}

	Matrix4 Matrix4::RotateY(float angleRad) {
		Matrix4 mat = Identity();
		float c = std::cos(angleRad), s = std::sin(angleRad);
		mat.m[0] = c; mat.m[2] = s;
		mat.m[8] = -s; mat.m[10] = c;
		return mat;
	}

	Matrix4 Matrix4::RotateZ(float angleRad) {
		Matrix4 mat = Identity();
		float c = std::cos(angleRad), s = std::sin(angleRad);
		mat.m[0] = c; mat.m[1] = -s;
		mat.m[4] = s; mat.m[5] = c;
		return mat;
	}

}