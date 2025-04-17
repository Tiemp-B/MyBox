FROM nginx:latest


FROM nginx:alpine AS production-stage

COPY --from=build-stage /app/dist /usr/share/nginx/html

CMD ["nginx", "-g", "daemon off;"]
# COPY ./nginx /etc/nginx

# COPY conf.d/ /etc/nginx/conf.d/