#include <cmath>

class Vec3 {
	public:
		Vec3() : v{0.0f, 0.0f, 0.0f} {}
		Vec3(float _x, float _y, float _z) : v{_x, _y, _z} {}

		float x() const { return v[0]; }
		float y() const { return v[1]; }
		float z() const { return v[2]; }
		
		const float& operator[](std::size_t i) const {
			return v[i];
		}

		void operator+=(const Vec3 &other) {
			v[0] += other.x();
			v[1] += other.y();
			v[2] += other.z();
		}

		void operator-=(const Vec3 &other) {
			v[0] -= other.x();
			v[1] -= other.y();
			v[2] -= other.z();
		}

		void operator/=(const Vec3 &other) {
			v[0] /= other.x();
			v[1] /= other.y();
			v[2] /= other.z();
		}

		Vec3 cross(const Vec3 &other) {
			return Vec3(
				v[1] * other.z() - v[2] * other.y(),
				v[2] * other.x() - v[0] * other.z(),
				v[0] * other.y() - v[1] * other.x()
			);
		}

		float dot(const Vec3 &other) {
			return v[0] * other.x() + v[1] * other.y() + v[2] * other.z();
		}

		float magnitude() {
			return std::sqrt(
				std::pow(v[0], 2) + 
				std::pow(v[1], 2) + 
				std::pow(v[2], 2)
			);
		}

		Vec3 normalize() {
			float l = this->magnitude();
			return Vec3(
				v[0] / l,
				v[1] / l,
				v[2] / l
			);
		}

	private:
		float v[3];
};

inline Vec3 operator+(Vec3 &a, Vec3 &b) { 
	return Vec3(
		a[0] + b[0],
		a[1] + b[2],
		a[2] + b[2]
	); 
}

inline Vec3 operator-(Vec3 &a, Vec3 &b) {
	return Vec3(
		a[0] - b[0],
		a[1] - b[1],
		a[2] - b[2]
	);
}

inline std::ostream& operator<<(std::ostream& os, const Vec3 &v) {
	os << "Vec3(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
	return os;
}


inline Vec3 operator*(Vec3 &a, Vec3 &b) {
	return Vec3(
		a[0] * b[0],
		a[1] * b[1],
		a[2] * b[2]
	);
}


