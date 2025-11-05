#pragma once

namespace Math {

	// Constants
	constexpr float pi = 3.14159265358979323846;
	constexpr float e = 2.71828182845904523536;
	constexpr float epsilon = 1e-6f; // for float comparisons

	// Utility functions
	inline float DegToRad(float deg);
	inline float RadToDeg(float rad);

	struct Vector2 {
		float x = 0.0f;
		float y = 0.0f;

		Vector2() = default;
		Vector2(float _x, float _y);

		static inline Vector2 Zeros();
		static inline Vector2 Ones();

		Vector2 operator+(const Vector2& v) const;
		Vector2 operator-(const Vector2& v) const;
		Vector2 operator*(float s) const;
		Vector2 operator/(float s) const;

		Vector2& operator+=(const Vector2& v);
		Vector2& operator-=(const Vector2& v);
		Vector2& operator*=(float s);
		Vector2& operator/=(float s);

		bool operator==(const Vector2& v) const;
		bool operator!=(const Vector2& v) const;

		Vector2 operator-() const;

		inline float Magnitude() const;
		inline float SqrMagnitude() const;
		inline Vector2 Normalized() const;
		static inline float Dot(const Vector2& a, const Vector2& b);
		static inline Vector2 Lerp(const Vector2& a, const Vector2& b, float t);
	};

	struct Vector3 {
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		Vector3() = default;
		Vector3(float _x, float _y, float _z);

		static inline Vector3 Zeros();
		static inline Vector3 Ones();

		Vector3 operator+(const Vector3& v) const;
		Vector3 operator-(const Vector3& v) const;
		Vector3 operator*(float s) const;
		Vector3 operator/(float s) const;

		Vector3& operator+=(const Vector3& v);
		Vector3& operator-=(const Vector3& v);
		Vector3& operator*=(float s);
		Vector3& operator/=(float s);

		bool operator==(const Vector3& v) const;
		bool operator!=(const Vector3& v) const;

		Vector3 operator-() const;

		inline float Magnitude() const;
		inline float SqrMagnitude() const;
		inline Vector3 Normalized() const;
		static inline float Dot(const Vector3& a, const Vector3& b);
		static inline Vector3 Cross(const Vector3& a, const Vector3& b);
		static inline Vector3 Lerp(const Vector3& a, const Vector3& b, float t);
	};

	struct Vector4 {
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		float w = 0.0f;

		Vector4() = default;
		Vector4(float _x, float _y, float _z, float _w);

		static inline Vector4 Zeros();
		static inline Vector4 Ones();

		Vector4 operator+(const Vector4& v) const;
		Vector4 operator-(const Vector4& v) const;
		Vector4 operator*(float s) const;
		Vector4 operator/(float s) const;

		Vector4& operator+=(const Vector4& v);
		Vector4& operator-=(const Vector4& v);
		Vector4& operator*=(float s);
		Vector4& operator/=(float s);

		bool operator==(const Vector4& v) const;
		bool operator!=(const Vector4& v) const;

		Vector4 operator-() const;

		inline float Magnitude() const;
		inline float SqrMagnitude() const;
		inline Vector4 Normalized() const;
		static inline float Dot(const Vector4& a, const Vector4& b);
		static inline Vector4 Lerp(const Vector4& a, const Vector4& b, float t);
	};

	struct Matrix4 {
		float m[16] = { 0 };

		Matrix4();

		inline Matrix4 operator*(const Matrix4& mat) const;
		inline Vector3 operator*(const Vector3& v) const;

		static inline Matrix4 Identity();
		static inline Matrix4 Translate(const Vector3& pos);
		static inline Matrix4 Scale(const Vector3& scale);
		static inline Matrix4 RotateX(float angleRad);
		static inline Matrix4 RotateY(float angleRad);
		static inline Matrix4 RotateZ(float angleRad);
	};
}
