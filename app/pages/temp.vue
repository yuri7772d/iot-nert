<template>
  <h1 class="bg-blue-200">Temp : {{ temp }}</h1>
  <div class="w-10 h-52 bg-gray-200">
    <div class="bg-red-500 " :style="{ height: temp + '%' }"></div>
  </div>

    <div class="flex flex-col items-center">
    <div class="w-10 h-52 bg-gray-200 rounded-full relative overflow-hidden border">
      <div
        class="absolute bottom-0 w-full bg-gradient-to-t from-red-600 via-orange-400 to-yellow-200 transition-all duration-500"
        :style="{ height: temp + '%' }"
      ></div>
    </div>
    <div class="mt-4 text-xl font-bold">
      {{ realTemp }}°C
    </div>
  </div>
</template>

<script setup>
const temp = ref(0);
async function load() {
  const result = await $fetch("http://10.189.41.34:1880/temp");
  console.log(result);

  temp.value = result.t;
}
onMounted(() => {
  setInterval(load, 1000);
});
</script>

<style scoped>
.thermo-container {
  width: 40px;
  height: 200px;
  border-radius: 20px;
  background: #ddd;
  overflow: hidden;
}
.thermo-bar {
  width: 100%;
  background: linear-gradient(to top, red, orange, yellow);
  transition: height 0.5s;
}
</style>
