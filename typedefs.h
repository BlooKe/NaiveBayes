#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef enum { DATA_DAY, DATA_SEASON, DATA_WIND, DATA_RAIN, DATA_CLASS } data_type_t;

typedef enum {WEEKDAY, HOLIDAY, SUNDAY, SATURDAY} day_t;
typedef enum {WINTER, SPRING, SUMMER, AUTUMN} season_t;
typedef enum {NONE, NORMAL, HIGH} wind_t;
typedef enum {NONE_r, SLIGHT, HEAVY} rain_t;
typedef enum {ONTIME, LATE, VERYLATE, CANCELLED} class_t;

typedef struct {
    day_t data_day;
    season_t data_season;
    wind_t data_wind;
    rain_t data_rain;
    class_t data_class;
} Data_t;

typedef struct {
    double ontime;
    double late;
    double verylate;
    double cancelled;
} Results_t;

#endif // TYPEDEFS_H
