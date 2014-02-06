#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#endif // DEFINITIONS_H


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
